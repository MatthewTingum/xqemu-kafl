/*
 * This file is part of Redqueen.
 *
 * Sergej Schumilo, 2019 <sergej@schumilo.de>
 * Cornelius Aschermann, 2019 <cornelius.aschermann@rub.de>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#pragma once

#include "qemu/osdep.h"
#include <linux/kvm.h>

void synchronization_check_reload_pending(CPUState *cpu);
void synchronization_unlock(void);
void synchronization_lock(CPUState *cpu);
void synchronization_reload_vm(void);
void synchronization_disable_pt(CPUState *cpu);
