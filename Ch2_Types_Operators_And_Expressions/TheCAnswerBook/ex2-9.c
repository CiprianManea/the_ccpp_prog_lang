/*
 * Author   : Dennis M. Ritchie
 * Date     : 28-02-2015
 * ----------------------------
 *  In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x.
 * Explain why. Use this observation to write a faster version of bitcoin.
 */

#include <stdio.h>

int bitcount(unsigned x);

int main()
{
    int x = 0xfa;

    printf("How many 1-bits are in 0x%x? A: %d\n", x, bitcount(x));

    return 0;
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= x-1)
        b++;

    return b;
}
