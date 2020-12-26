/*
 * This file is part of Redqueen.
 *
 * Sergej Schumilo, 2019 <sergej@schumilo.de>
 * Cornelius Aschermann, 2019 <cornelius.aschermann@rub.de>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later 
 */


#ifndef INTERFACE_H
#define INTERFACE_H

#define INTEL_PT_MAX_RANGES			4

#define DEFAULT_KAFL_BITMAP_SIZE	0x10000
#define DEFAULT_EDGE_FILTER_SIZE	0x1000000

#define PROGRAM_SIZE				(128 << 20) /* 128MB Application Data */
#define PAYLOAD_SIZE				(128 << 10)	/* 128KB Payload Data */
#define INFO_SIZE					(128 << 10)	/* 128KB Info Data */
#define HPRINTF_SIZE				0x1000 		/* 4KB hprintf Data */

#define INFO_FILE					"/tmp/kAFL_info.txt"
#define HPRINTF_FILE				"/tmp/kAFL_printf.txt"

#define HPRINTF_LIMIT				512

#define KAFL_PROTO_ACQUIRE			'R'
#define KAFL_PROTO_RELEASE			'D'

#define KAFL_PROTO_RELOAD			'L'
#define KAFL_PROTO_ENABLE_SAMPLING	'S'
#define KAFL_PROTO_DISABLE_SAMPLING	'O'
#define KAFL_PROTO_COMMIT_FILTER	'T'
#define KAFL_PROTO_FINALIZE			'F'

#ifdef CONFIG_REDQUEEN
#define KAFL_PROTO_ENABLE_RQI_MODE	'A'
#define KAFL_PROTO_DISABLE_RQI_MODE	'B'
#define KAFL_PROTO_ENABLE_TRACE_MODE 'E'
#define KAFL_PROTO_DISABLE_TRACE_MODE 'G'
#define KAFL_PROTO_ENABLE_PATCHES 'P'
#define KAFL_PROTO_DISABLE_PATCHES 'Q'
#define KAFL_PROTO_REDQUEEN_SET_LIGHT_INSTRUMENTATION     'U'
#define KAFL_PROTO_REDQUEEN_SET_SE_INSTRUMENTATION        'V'
#define KAFL_PROTO_REDQUEEN_SET_WHITELIST_INSTRUMENTATION 'W'
#define KAFL_PROTO_REDQUEEN_SET_BLACKLIST 'X'
#endif

#define KAFL_PROTO_CRASH			'C'
#define KAFL_PROTO_KASAN			'K'
#define KAFL_PROTO_TIMEOUT		't'
#define KAFL_PROTO_INFO				'I'

#define KAFL_PROTO_PRINTF			'X'

#define KAFL_PROTO_PT_TRASHED			'Z'	/* thank you Intel! */
#define KAFL_PROTO_PT_TRASHED_CRASH		'M'
#define KAFL_PROTO_PT_TRASHED_KASAN		'N'

#define KAFL_PROTO_PT_ABORT				'H'



#endif
