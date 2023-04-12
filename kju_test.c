/*
 * The compilation and/or linking is done using the great
 * SAS/C Amiga Compiler 6.00 (Copyright (c) 1988-1992 SAS Institute Inc.)
 *
 * CLI (shell) command: sc link kju_test.c
 * Hint: MATH=STANDARD
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <proto/dos.h>
#include <proto/exec.h>

#include "kju.h"
#include "kju_protos.h"


/*
 *****  MAIN
 */
int main(void)
{
    struct Library *KjuBase;
    clock_t start_t, end_t;
    double total_t;

    long a, b, x, y, z;

    start_t = clock();
    if (!(KjuBase = OpenLibrary("kju.library", 1L)))
    {
        printf("failed open \"kju.library\"\n");
        exit(1);
    }
    else
    {
        printf("\n+-------------------------+\n");
        printf("|  TESTING KJU FUNCTIONS  |\n");
        printf("+-------------------------+\n\n");


        /*** AND ***/
        x = TRUE; y = TRUE;
        z = KJU_AND(x, y);
        printf("AND(%ld, %ld) = %ld\n", x, y, z);
        x = TRUE; y = FALSE;
        z = KJU_AND(x, y);
        printf("AND(%ld, %ld) = %ld\n", x, y, z);
        x = FALSE; y = TRUE;
        z = KJU_AND(x, y);
        printf("AND(%ld, %ld) = %ld\n", x, y, z);
        x = FALSE; y = FALSE;
        z = KJU_AND(x, y);
        printf("AND(%ld, %ld) = %ld\n", x, y, z);

        /*** OR ***/
        x = TRUE; y = TRUE;
        z = KJU_OR(x, y);
        printf("OR(%ld, %ld) = %ld\n", x, y, z);
        x = TRUE; y = FALSE;
        z = KJU_OR(x, y);
        printf("OR(%ld, %ld) = %ld\n", x, y, z);
        x = FALSE; y = TRUE;
        z = KJU_OR(x, y);
        printf("OR(%ld, %ld) = %ld\n", x, y, z);
        x = FALSE; y = FALSE;
        z = KJU_OR(x, y);
        printf("OR(%ld, %ld) = %ld\n", x, y, z);

        /*** NOT ***/
        x = TRUE;
        z = KJU_NOT(x);
        printf("NOT(%ld) = %ld\n", x, z);
        x = FALSE;
        z = KJU_NOT(x);
        printf("NOT(%ld) = %ld\n", x, z);

        /*** NAND ***/
        x = TRUE; y = TRUE;
        z = KJU_NAND(x, y);
        printf("NAND(%ld, %ld) = %ld\n", x, y, z);
        x = TRUE; y = FALSE;
        z = KJU_NAND(x, y);
        printf("NAND(%ld, %ld) = %ld\n", x, y, z);
        x = FALSE; y = TRUE;
        z = KJU_NAND(x, y);
        printf("NAND(%ld, %ld) = %ld\n", x, y, z);
        x = FALSE; y = FALSE;
        z = KJU_NAND(x, y);
        printf("NAND(%ld, %ld) = %ld\n", x, y, z);

        /*** NOR ***/
        x = TRUE; y = TRUE;
        z = KJU_NOR(x, y);
        printf("NOR(%ld, %ld) = %ld\n", x, y, z);
        x = TRUE; y = FALSE;
        z = KJU_NOR(x, y);
        printf("NOR(%ld, %ld) = %ld\n", x, y, z);
        x = FALSE; y = TRUE;
        z = KJU_NOR(x, y);
        printf("NOR(%ld, %ld) = %ld\n", x, y, z);
        x = FALSE; y = FALSE;
        z = KJU_NOR(x, y);
        printf("NOR(%ld, %ld) = %ld\n", x, y, z);

        /*** XOR ***/
        x = TRUE; y = TRUE;
        z = KJU_XOR(x, y);
        printf("XOR(%ld, %ld) = %ld\n", x, y, z);
        x = TRUE; y = FALSE;
        z = KJU_XOR(x, y);
        printf("XOR(%ld, %ld) = %ld\n", x, y, z);
        x = FALSE; y = TRUE;
        z = KJU_XOR(x, y);
        printf("XOR(%ld, %ld) = %ld\n", x, y, z);
        x = FALSE; y = FALSE;
        z = KJU_XOR(x, y);
        printf("XOR(%ld, %ld) = %ld\n", x, y, z);

        /*** XNOR ***/
        x = TRUE; y = TRUE;
        z = KJU_XNOR(x, y);
        printf("XNOR(%ld, %ld) = %ld\n", x, y, z);
        x = TRUE; y = FALSE;
        z = KJU_XNOR(x, y);
        printf("XNOR(%ld, %ld) = %ld\n", x, y, z);
        x = FALSE; y = TRUE;
        z = KJU_XNOR(x, y);
        printf("XNOR(%ld, %ld) = %ld\n", x, y, z);
        x = FALSE; y = FALSE;
        z = KJU_XNOR(x, y);
        printf("XNOR(%ld, %ld) = %ld\n", x, y, z);

        /*** IMP ***/
        x = TRUE; y = TRUE;
        z = KJU_IMP(x, y);
        printf("IMP(%ld, %ld) = %ld\n", x, y, z);
        x = TRUE; y = FALSE;
        z = KJU_IMP(x, y);
        printf("IMP(%ld, %ld) = %ld\n", x, y, z);
        x = FALSE; y = TRUE;
        z = KJU_IMP(x, y);
        printf("IMP(%ld, %ld) = %ld\n", x, y, z);
        x = FALSE; y = FALSE;
        z = KJU_IMP(x, y);
        printf("IMP(%ld, %ld) = %ld\n", x, y, z);

        /*** ABS ***/
        x = -2520;
        z = KJU_ABS(x);
        printf("ABS(%ld) = %ld\n", x, z);
        x = 171;
        z = KJU_ABS(x);
        printf("ABS(%ld) = %ld\n", x, z);

        /*** MAX ***/
        x = 42; y = 13;
        z = KJU_MAX(x, y);
        printf("MAX(%ld, %ld) = %ld\n", x, y, z);
        x = -42; y = 13;
        z = KJU_MAX(x, y);
        printf("MAX(%ld, %ld) = %ld\n", x, y, z);
        x = 13; y = 42;
        z = KJU_MAX(x, y);
        printf("MAX(%ld, %ld) = %ld\n", x, y, z);
        x = 13; y = -42;
        z = KJU_MAX(x, y);
        printf("MAX(%ld, %ld) = %ld\n", x, y, z);

        /*** MIN ***/
        x = 42; y = 13;
        z = KJU_MIN(x, y);
        printf("MIN(%ld, %ld) = %ld\n", x, y, z);
        x = -42; y = 13;
        z = KJU_MIN(x, y);
        printf("MIN(%ld, %ld) = %ld\n", x, y, z);
        x = 13; y = 42;
        z = KJU_MIN(x, y);
        printf("MIN(%ld, %ld) = %ld\n", x, y, z);
        x = 13; y = -42;
        z = KJU_MIN(x, y);
        printf("MIN(%ld, %ld) = %ld\n", x, y, z);

        /*** SWAP ***/
        a = 5; b = 7;
        printf("Before SWAP(): a = %ld, b = %ld\n", a, b);
        KJU_SWAP(&a, &b);
        printf("After  SWAP(): a = %ld, b = %ld\n", a, b);
        a = -5; b = -7;
        printf("Before SWAP(): a = %ld, b = %ld\n", a, b);
        KJU_SWAP(&a, &b);
        printf("After  SWAP(): a = %ld, b = %ld\n", a, b);
        a = -5; b = 7;
        printf("Before SWAP(): a = %ld, b = %ld\n", a, b);
        KJU_SWAP(&a, &b);
        printf("After  SWAP(): a = %ld, b = %ld\n", a, b);

        /*** REBOOT? ***/
        KJU_REBOOT();

    }

    if (KjuBase != NULL) CloseLibrary(KjuBase);

    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("\nTotal time taken by CPU: %lf\n\n", total_t);

    return 0;
}
