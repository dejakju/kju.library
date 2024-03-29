/*
 * $VER: kju.c 1.0 (12.04.2023)
 *
 * compiled and linked as 'Shared Library' using the NOT so great
 * StormC 3.0 Professional (Copyright 1995-97 HAAGE & PARTNER Computer GmbH)
 *
 * -- Goran Todorovic
 */

// Standard C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// AmigaOS
#include <exec/types.h>
#include <exec/libraries.h>
#include <intuition/intuition.h>
#include <proto/exec.h>
#include <proto/intuition.h>

// Custom
#include "kju.h"

#pragma libbase KjuBase


/*
 ***	FUNCTION DEFINITIONS
 */

// Logical AND
long KJU_AND(register __d0 long a, register __d1 long b, register __a6 KjuBase *base)
{
	return a && b;
}

// Logical OR
long KJU_OR(register __d0 long a, register __d1 long b, register __a6 KjuBase *base)
{
	return a || b;
}

// Logical NOT
long KJU_NOT(register __d0 long a, register __a6 KjuBase *base)
{
	return !a;
}

// Logical NOT AND
long KJU_NAND(register __d0 long a, register __d1 long b, register __a6 KjuBase *base)
{
	return !(a && b);
}

// Logical NOT OR
long KJU_NOR(register __d0 long a, register __d1 long b, register __a6 KjuBase *base)
{
	return !(a || b);
}

// Logical Exclusive OR
long KJU_XOR(register __d0 long a, register __d1 long b, register __a6 KjuBase *base)
{
	return !a && b || a && !b;
}

// Logical Exclusive NOT OR
long KJU_XNOR(register __d0 long a, register __d1 long b, register __a6 KjuBase *base)
{
	return a && b || !a && !b;
}

// Logical Imperative
long KJU_IMP(register __d0 long a, register __d1 long b, register __a6 KjuBase *base)
{
	return !(a && !b)
}

// Return Absolute Value
long KJU_ABS(register __d0 long a, register __a6 KjuBase *base)
{
	return (a < 0) ? -a : a;
}

// Return Maximum Value
long KJU_MAX(register __d0 long a, register __d1 long b, register __a6 KjuBase *base)
{
	return (a > b) ? a : b;
}

// Return Minimum Value
long KJU_MIN(register __d0 long a, register __d1 long b, register __a6 KjuBase *base)
{
	return (a < b) ? a : b;
}

// Swap numeric values without a temporary variable
void KJU_SWAP(register __d0 long *a, register __d1 long *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}


/*
 ***	AMIGA-OS FUNCTIONS
 */

// Open a Intuition requester with provided title, body and gadget text
ULONG KJU_REQUEST(register __d1 UBYTE *reqtitle, register __d2 UBYTE *body, register __d3 UBYTE *gadgets)
{
	UBYTE *title = reqtitle;
	struct EasyStruct estr;

	/* struct EasyStruct __aligned estr; */

	estr.es_StructSize   = sizeof(struct EasyStruct);
	estr.es_Flags        = NULL;
	estr.es_Title        = title;
	estr.es_TextFormat   = body;
	estr.es_GadgetFormat = gadgets;

	return ((ULONG) EasyRequestArgs(NULL, &estr, NULL, NULL));
}

// Reboot the system
void KJU_REBOOT()
{
	ULONG res;
	res = KJU_REQUEST("System Request", "Do you really want to reboot your machine?\n\n*** WARNING: ALL unsaved data will be lost!", "Yes|No");

	if (res == 1)
		ColdReboot();
}


/*
 ***	ASSEMBLER FUNCTION DEFINITIONS
 */

// n/a yet

