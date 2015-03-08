/*
 * Author   : Ciprian Manea
 * Date     : 08-03-2015
 * ----------------------------
 *  In a two's complement number representation, our version of itoa does
 * not handle the largest negative number, that is, the value of n equal
 * to -(2^wordsize-1). Explain why not. Modify it to print that value
 * correctly, reagardless of the machine on which it runs.
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[]);

int main()
{
    char s[22];
    int n = INT_MIN;

    itoa(n, s);
    printf("n value as: %s\n", s);

    return 0;
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;
    
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;
    long long n_long = n;

    if ((sign = n) < 0)     /* record sign */
        n_long = -n_long;             /* make n positive */
    i = 0;
    do {                    /* generate digits in reverse order */
        s[i++] = n_long % 10 + '0';   /* get next digit */
    } while ((n_long /= 10) > 0);    /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
