/*
 * This file is part of Redqueen.
 *
 * Sergej Schumilo, 2019 <sergej@schumilo.de>
 * Cornelius Aschermann, 2019 <cornelius.aschermann@rub.de>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef LOGGER_H
#define LOGGER_H

	#define CREATE_VM_IMAGE
	//#define SAMPLE_RAW
	//#define SAMPLE_DECODED
	//#define SAMPLE_DECODED_DETAILED
	//#define SAMPLE_RAW_SINGLE
	
	#ifdef CREATE_VM_IMAGE
		#define DECODER_MEMORY_IMAGE "/tmp/data"
	#endif

	#ifdef SAMPLE_RAW_SINGLE
		void init_sample_raw_single(uint32_t id);
		void sample_raw_single(void* buffer, int bytes);
	#endif
	
	#ifdef SAMPLE_RAW
		void init_sample_raw(void);
		void sample_raw(void* buffer, int bytes);
	#endif

	#ifdef SAMPLE_DECODED
		void init_sample_decoded(void);
		void sample_decoded(uint64_t addr);
	#endif

	#ifdef SAMPLE_DECODED_DETAILED
		void init_sample_decoded_detailed(void);
	#endif

	void sample_decoded_detailed(const char *format, ...);

#define UNUSED(x) (void)x;

#ifdef SAMPLE_DECODED
#define WRITE_SAMPLE_DECODED(addr) (sample_decoded(addr))
#endif

#ifdef SAMPLE_DECODED_DETAILED
#define WRITE_SAMPLE_DECODED_DETAILED(format, ...) (sample_decoded_detailed(format, ##__VA_ARGS__))
#else
#define WRITE_SAMPLE_DECODED_DETAILED(format, ...)  (void)0
#endif


#endif
