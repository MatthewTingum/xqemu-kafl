/*
 * This file is part of Redqueen.
 *
 * Sergej Schumilo, 2019 <sergej@schumilo.de>
 * Cornelius Aschermann, 2019 <cornelius.aschermann@rub.de>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef TNT_CACHE_H
#define TNT_CACHE_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define NOT_TAKEN			0
#define TAKEN				1
#define TNT_EMPTY			2

#define SHORT_TNT_OFFSET	1
#define SHORT_TNT_MAX_BITS	8-1-SHORT_TNT_OFFSET

#define LONG_TNT_OFFSET		16
#define LONG_TNT_MAX_BITS	64-1-LONG_TNT_OFFSET

#define BUF_SIZE 0x1000000      /* 16777216 slots */

typedef struct tnt_cache_s{
	uint8_t* tnt_memory;
	uint64_t pos;
	uint64_t max;
	uint64_t tnt;
} tnt_cache_t;

tnt_cache_t* tnt_cache_init(void);
void tnt_cache_destroy(tnt_cache_t* self);
void tnt_cache_flush(tnt_cache_t* self);


bool is_empty_tnt_cache(tnt_cache_t* self);
int count_tnt(tnt_cache_t* self);
uint8_t process_tnt_cache(tnt_cache_t* self);

void append_tnt_cache(tnt_cache_t* self, uint8_t data);
void append_tnt_cache_ltnt(tnt_cache_t* self, uint64_t data);

#endif
