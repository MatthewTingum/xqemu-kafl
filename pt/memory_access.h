/*
 * This file is part of Redqueen.
 *
 * Sergej Schumilo, 2019 <sergej@schumilo.de>
 * Cornelius Aschermann, 2019 <cornelius.aschermann@rub.de>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */


#ifndef MEMORY_ACCESS_H
#define MEMORY_ACCESS_H

#include "qemu/osdep.h"
#include <linux/kvm.h>
#include "qemu-common.h"
#include "sysemu/kvm_int.h"

#define x86_64_PAGE_SIZE	0x1000
#define x86_64_PAGE_MASK	~(x86_64_PAGE_SIZE - 1)

bool read_virtual_memory(uint64_t address, uint8_t* data, uint32_t size, CPUState *cpu);
bool write_virtual_memory(uint64_t address, uint8_t* data, uint32_t size, CPUState *cpu);
void hexdump_virtual_memory(uint64_t address, uint32_t size, CPUState *cpu);
bool write_virtual_shadow_memory(uint64_t address, uint8_t* data, uint32_t size, CPUState *cpu);
bool is_addr_mapped(uint64_t address, CPUState *cpu);
#endif
