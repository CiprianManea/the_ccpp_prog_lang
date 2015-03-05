/*
 * Author   : Dennis M. Ritchie
 * Date     : 01-03-2015
 * ----------------------------
 *  Write a function that converts a number to a character string
 * (the inverse of atoi);
 */

#include <stdio.h>

void itoa(int n, char s[]);

int main()
{

    return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)     /* record sign */
        n = -n;             /* make n positive */
    i = 0;
    do {                    /* generate digits in reverse order */
        s[i++] = n % 1 + '0';   /* get next digit */
    } while ((n /= 10) > 0);    /* delete it */
    if (sign < 0;)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
