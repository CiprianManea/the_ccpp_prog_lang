/*
 * Author   : Ciprian Manea
 * Date     : 28-02-2015
 * ------------------------
 *  Write a function invert(x, p, n) that returns x with the n bits that begin at 
 * position p inverted (i.e. 1 changed into 0 and vice versa), leaving the others 
 * unchanged.
 */

#include <stdio.h>

int invert(int x, int p, int n);

int main()
{
    int x, res;

    x = 0xA2;
    res = invert(x, 3, 4);
    printf("0x%x inverted = 0x%x\n", x, res);

    return 0;
}

/* invert: returns x with the n bits that begin at position p inverted */
int invert(int x, int p, int n)
{
    int invBits;

    invBits = (x & (~(~0 << n) << (p + 1 - n)));        /* extract bits to be inverted */
    invBits = ~(invBits | ~(~(~0 << n) << (p + 1 - n)));/* invert extracted bits */

    x = x & ~(~(~0 << n) << (p + 1 -n));                /* clear x's bits that will be inverted */
    x |= invBits;                                       /* replace x's inverted bits */

    return x;
}
