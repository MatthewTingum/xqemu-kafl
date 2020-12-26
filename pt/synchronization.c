/*
 * This file is part of Redqueen.
 *
 * Sergej Schumilo, 2019 <sergej@schumilo.de>
 * Cornelius Aschermann, 2019 <cornelius.aschermann@rub.de>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "pt/synchronization.h"
#include "pt/hypercall.h"
#include "pt/interface.h"
#include "qemu-common.h"
#include "qemu/osdep.h"
#include "cpu.h"
#include "sysemu/sysemu.h"
//#include "sysemu/runstate.h"
#include "sysemu/kvm.h"
#include "pt.h"

pthread_mutex_t synchronization_lock_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t synchronization_lock_condition = PTHREAD_COND_INITIALIZER;
pthread_mutex_t synchronization_disable_pt_mutex = PTHREAD_MUTEX_INITIALIZER;

volatile bool synchronization_reload_pending = false;
volatile bool synchronization_kvm_loop_waiting = false;

void synchronization_check_reload_pending(CPUState *cpu){
	bool value;
	pthread_mutex_lock(&synchronization_lock_mutex);
	value = synchronization_reload_pending;
	if(value){
		atomic_set(&cpu->kvm_run->immediate_exit, 1);
	}
	pthread_mutex_unlock(&synchronization_lock_mutex);
}

void synchronization_unlock(void){
	pthread_mutex_lock(&synchronization_lock_mutex);
	pthread_cond_signal(&synchronization_lock_condition);
	hypercall_reset_hprintf_counter();
	pthread_mutex_unlock(&synchronization_lock_mutex);
}	

void synchronization_lock(CPUState *cpu){

	pthread_mutex_lock(&synchronization_lock_mutex);
	if(!synchronization_reload_pending){
		synchronization_kvm_loop_waiting = true;

		if(cpu->intel_pt_run_trashed){
			//fprintf(stderr, "KAFL_PROTO_PT_TRASHED\n");
			hypercall_snd_char(KAFL_PROTO_PT_TRASHED);
			cpu->intel_pt_run_trashed = false;
		} 
		else {
			hypercall_snd_char(KAFL_PROTO_ACQUIRE);
		}
	}
	else{
		atomic_set(&cpu->kvm_run->immediate_exit, 1);
		pthread_mutex_unlock(&synchronization_lock_mutex);
		return;
	}
	pthread_cond_wait(&synchronization_lock_condition, &synchronization_lock_mutex);
	synchronization_kvm_loop_waiting = false;
	pthread_mutex_unlock(&synchronization_lock_mutex);
}	

void synchronization_reload_vm(void){
	CPUState *cpu = qemu_get_cpu(0);
	assert(false);

	pthread_mutex_lock(&synchronization_lock_mutex);
	synchronization_reload_pending = true;
	if(synchronization_kvm_loop_waiting){
		pthread_cond_signal(&synchronization_lock_condition);
	}
	hypercall_reset_hprintf_counter();
	synchronization_disable_pt(cpu);
	pthread_mutex_unlock(&synchronization_lock_mutex);

	//kvm_cpu_synchronize_state(cpu);
	vm_stop(RUN_STATE_RESTORE_VM);


	pthread_mutex_lock(&synchronization_lock_mutex);

	//fast_loadvm();

	synchronization_reload_pending = false;
	synchronization_kvm_loop_waiting = false;
	atomic_set(&cpu->kvm_run->immediate_exit, 0);

	hypercall_snd_char(KAFL_PROTO_RELOAD);
	pthread_mutex_unlock(&synchronization_lock_mutex);

	vm_start();
	//kvm_cpu_synchronize_state(cpu);
}

void synchronization_disable_pt(CPUState *cpu){
	pthread_mutex_lock(&synchronization_disable_pt_mutex);
	pt_disable(cpu, false);
	pt_sync();
	//kvm_cpu_synchronize_state(cpu);
	pthread_mutex_unlock(&synchronization_disable_pt_mutex);
}
