/*
 * Author   : Dennis M. Ritchie
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

/* invert: inverts the n bits of x that begin at position p */
int invert(int x, int p, int n)
{
    return x ^ (~(~0 << n) << (p+1-n));
}
