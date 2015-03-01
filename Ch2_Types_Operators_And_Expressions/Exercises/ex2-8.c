/*
 * Author   : Ciprian Manea
 * Date     : 28-02-2015
 * ------------------------
 *  Write a function rightrot(x, n) that returns the value of the integer x
 * rotated to the right by n bit positions.
 */

#include <stdio.h>

int rightrot(unsigned int x, int n);
int wordLength(void);

int main()
{
    unsigned int x;

    x = 0xAA;
    printf("0x%x rotated %d times : 0x%x\n", x, 4, rightrot(x, 4));

    return 0;
}

/* rightrot: returns x's value rotated to the right by n bit positions. */
int rightrot(unsigned int x, int n)
{
    int i, tmp;

    tmp = 0;
    for (i = 0; i < n; i++) {
        tmp = (x & 1) << (wordLength() - 1);
        x >>= 1;
        x |= tmp;
    }

    return x;
}

/* wordLength: computes word length of the machine */
int wordLength(void)
{
    int i;
    unsigned int v = (unsigned int)~0;

    for (i = 1; (v = v >> 1) > 0; i++)
        ;
    return i;
}
