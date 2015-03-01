/*
 * Author   : Dennis M. Ritchie
 * Date     : 28-02-2015
 * ------------------------
 *  Write a function setbits(x, p, n, y) that returns x with the n bits
 * that begin at position p set to the rightmost n bits of y, leaving the 
 * other bits unchanged.
 */

#include <stdio.h>

int setbits(int x, int p, int n, int y);
void bin_prnt_int(int x);

int main()
{
    int x, y, res;

    x = 0xA00F;
    y = 0;

    res = setbits(x, 3, 4, y);
    printf("res = ");
    bin_prnt_int(res);

    return 0;
}

int setbits(int x, int p, int n, int y)
{
    return x & ~(~(~0 << n) << (p+1-n)) | (y & ~(~0 << n)) << (p+1-n);
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
