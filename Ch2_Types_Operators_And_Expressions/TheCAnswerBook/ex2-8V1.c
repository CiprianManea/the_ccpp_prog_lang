/*
 * Author   : Dennis M. Ritchie
 * Date     : 28-02-2015
 * ------------------------
 *  Write a function rightrot(x, n) that returns the value of the integer x
 * rotated to the right by n bit positions.
 */

#include <stdio.h>

int rightrot(unsigned x, int n);

int main()
{
    unsigned int x;

    x = 0xAA;
    printf("0x%x rotated %d times : 0x%x\n", x, 4, rightrot(x, 4));

    return 0;
}

/* rightrot: returns x's value rotated to the right by n bit positions. */
int rightrot(unsigned x, int n)
{
    int wordlength(void);
    int rbit;               /* rightmost bit */

    while (n-- > 0) {
        rbit = (x & 1) << (wordlength() - 1);
        x = x >> 1;         /* shift x 1 position right */
        x = x | rbit;       /* complete one rotation */
    }
    return x;
}

/* wordLength: computes word length of the machine */
int wordlength(void)
{
    int i;
    unsigned v = (unsigned)~0;

    for (i = 1; (v = v >> 1) > 0; i++)
        ;
    return i;
}
