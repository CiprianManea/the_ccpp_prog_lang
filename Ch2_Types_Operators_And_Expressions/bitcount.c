/*
 * Author   : Dennis M. Ritchie
 * Date     : 28-02-2015
 * ----------------------------
 *  Write a function bitcount(x), that counts the number of 1-bits in its
 * integer argument.
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

    for (b = 0; x != 0; x >>=1)
        if (x & 01)
            b++;

    return b;
}
