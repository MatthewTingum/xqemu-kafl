/*
 * This file is part of Redqueen.
 *
 * Sergej Schumilo, 2019 <sergej@schumilo.de>
 * Cornelius Aschermann, 2019 <cornelius.aschermann@rub.de>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef __GUARD_REDQUEEN_PATCH__
#define __GUARD_REDQUEEN_PATCH__

#include "qemu/osdep.h"
#include <linux/kvm.h>
#include "pt/patcher.h"

void pt_enable_patches(patcher_t *self);

void pt_disable_patches(patcher_t *self);
#endif
