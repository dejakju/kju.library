/*
 * $VER: kju_protos.h 1.0 (12.04.2023)
 *
 * compiled and linked as 'Shared Library' using the NOT so great
 * StormC 3.0 Professional (Copyright 1995-97 HAAGE & PARTNER Computer GmbH)
 *
 * -- Goran Todorovic
 */

#ifndef KJULIB_PROTOS_H
#define KJULIB_PROTOS_H

#ifdef __cplusplus
extern "C" {
#endif

/*** C/C++ PROTOTYPES *******************/
long KJU_AND(long a, long b);
long KJU_OR(long a, long b);
long KJU_NOT(long a);
long KJU_NAND(long a, long b);
long KJU_NOR(long a, long b);
long KJU_XOR(long a, long b);
long KJU_XNOR(long a, long b);
long KJU_IMP(long a, long b);
long KJU_ABS(long a);
long KJU_MAX(long a, long b);
long KJU_MIN(long a, long b);
void KJU_SWAP(long *a, long *b);

/**** AMIGA-OS PROTOTYPES ***************/
ULONG KJU_REQUEST(UBYTE *reqtitle, UBYTE *body, UBYTE *gadgets);
void KJU_REBOOT(void);

/**** ASSEMBLER PROTOTYPES **************/
// n/a

/****************************************/

#ifdef __cplusplus
};
#endif

/*** PRAGMA LIBCALL DEFINITIONS ***/

#pragma libcall KjuBase KJU_AND 1E 1002
#pragma libcall KjuBase KJU_OR 24 1002
#pragma libcall KjuBase KJU_NOT 2A 001
#pragma libcall KjuBase KJU_NAND 30 1002
#pragma libcall KjuBase KJU_NOR 36 1002
#pragma libcall KjuBase KJU_XOR 3C 1002
#pragma libcall KjuBase KJU_XNOR 42 1002
#pragma libcall KjuBase KJU_IMP 48 1002
#pragma libcall KjuBase KJU_ABS 4E 001
#pragma libcall KjuBase KJU_MAX 54 1002
#pragma libcall KjuBase KJU_MIN 5A 1002
#pragma libcall KjuBase KJU_SWAP 60 1002
#pragma libcall KjuBase KJU_REQUEST 66 32103
#pragma libcall KjuBase KJU_REBOOT 6C 0

#endif
