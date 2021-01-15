/*
 * This file is part of Redqueen.
 *
 * Sergej Schumilo, 2019 <sergej@schumilo.de>
 * Cornelius Aschermann, 2019 <cornelius.aschermann@rub.de>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later 
 */


#ifndef __FILTER__
#define __FILTER__

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

typedef struct filter_s {
  size_t size;
  uint16_t execs;
  uint16_t *counters;
  uint8_t *hit_bitmap;
  uint8_t *filter_bitmap;
  uint64_t prev_addr;
  uint64_t from_addr;
  uint64_t to_addr;
  uint32_t blacklist_count;
} filter_t;



filter_t* new_filter(uint64_t from, uint64_t to, uint8_t *filter_bitmap);

void filter_init_determinism_run(filter_t* self);

void filter_init_new_exec(filter_t* self);

void filter_add_address(filter_t* self, uint64_t addr);

void filter_finalize_exec(filter_t* self);

void filter_finalize_determinism_run(filter_t* self);

bool filter_is_address_nondeterministic(filter_t* self, uint64_t addr);

uint32_t filter_count_new_addresses(filter_t* self);

#endif
