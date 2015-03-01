/*
 * Author   : Ciprian Manea
 * Date     : 28-02-2015
 * ------------------------
 *  Write a function setbits(x, p, n, y) that returns x with the n bits
 * that begin at position p set to the rightmost n bits of y, leaving the 
 * other bits unchanged.
 * ------------------------
 *  Obs: First version is my understanding of the problem. Which was wrong!
 * Next time I will read the problem statement with better attention.
 */

#include <stdio.h>

int setbits(int x, int p, int n, int y);
void bin_prnt_int(int x);

int main()
{
    int nr = 0xA00F;
    int res;

    printf("nr = ");
    bin_prnt_int(nr);

    res = setbits(nr, 3, 4, 11);
    printf("res = ");
    bin_prnt_int(res);

    return 0;
}

int setbits(int x, int p, int n, int y)
{
    int get = 0, clr = 0;

    get = (x >> (p + 1 - n)) & ~(~0 << n);  /* get the value out of x */

    clr = (~0  << n);           /* create the mask to delete bites in x */
    clr <<= (y + 1 - n);        /* align the 0th bits that should be erase */

    get <<= (y + 1 - n);        /* align the bith that should be copied */
    x &= clr;                   /* erase the bits in x */
    x |= get;                   /* copy the bits */

    return x;
}

void bin_prnt_byte(int x)
{
    int n;
    for (n = 0; n < 8; n++) {
        if ((x & 0x80) != 0)
            printf("1");
        else 
            printf("0");

        if (n == 3)
            printf(" ");    /* insert a space between nybbles */
        x = x << 1;
    }
}

void bin_prnt_int(int x)
{
    int hi, lo;
    hi = (x >> 8) & 0xff;
    lo = x & 0xff;
    bin_prnt_byte(hi);
    printf(" ");
    bin_prnt_byte(lo);
    printf("\n");
}
