/*
 * This file is part of Redqueen.
 *
 * Sergej Schumilo, 2019 <sergej@schumilo.de>
 * Cornelius Aschermann, 2019 <cornelius.aschermann@rub.de>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */


#pragma once

typedef struct asm_operand_s{
	char* base;
	char* index;
	char* segment;
	uint64_t offset;
	uint8_t ptr_size;
	uint8_t scale;
	bool was_present;
} asm_operand_t;


void asm_decoder_compile(void);
void asm_decoder_parse_op(char* opstr, asm_operand_t* op);

void asm_decoder_print_op(asm_operand_t* op);

bool asm_decoder_is_imm(asm_operand_t* op);
void asm_decoder_clear(asm_operand_t* op);

bool asm_decoder_op_eql(asm_operand_t* op1, asm_operand_t* op2);
