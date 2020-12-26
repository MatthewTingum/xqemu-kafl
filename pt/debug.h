/* 
 * This file is part of Redqueen.
 *
 * Sergej Schumilo, 2019 <sergej@schumilo.de>
 * Cornelius Aschermann, 2019 <cornelius.aschermann@rub.de>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later 
 */



#pragma once

#define QEMU_PT_PRINT_PREFIX  "[QEMU-PT]\t"
#define CORE_PREFIX           "Core:      "
#define MEM_PREFIX            "Memory:    "
#define RELOAD_PREFIX         "Reload:    "
#define PT_PREFIX             "PT:        "
#define INTERFACE_PREFIX      "Interface: "
#define REDQUEEN_PREFIX       "Redqueen:  "
#define DISASM_PREFIX         "Disasm:    "

#define COLOR	"\033[1;35m"
#define ENDC	"\033[0m"


#define QEMU_PT_PRINTF(PREFIX, format, ...) printf (QEMU_PT_PRINT_PREFIX COLOR PREFIX format ENDC "\n", ##__VA_ARGS__)
#define QEMU_PT_PRINTF_DBG(PREFIX, format, ...) printf (QEMU_PT_PRINT_PREFIX PREFIX "(%s#:%d)\t"format, __BASE_FILE__, __LINE__, ##__VA_ARGS__)
