/*
 * Author   : Dennis M. Ritchie
 * Date     : 08-03-2015
 * ----------------------------
 *  Write the function itob(n, s, b) that converts the integer n into a base b
 * character representation in the string s. In particular, itob(n, s, 16)
 * formats n as a hexadecimal integer in s.
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

void itob(int n, char s[], int b);

int main()
{
    char s[22];
    int n = 2748;

    itob(n, s, 16);
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
void itob(int n, char s[], int b)
{
    int i, j, sign;

    if ((sign = n) < 0)             /* record sign */
        n = -n;           /* make n positive */
    i = 0;
    do {                    /* generate digits in reverse order */
        j = n % b;
        s[i++] = (j <= 9) ? j + '0' : j + 'a' - 10;
    } while ((n_long /= b) > 0);    /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
