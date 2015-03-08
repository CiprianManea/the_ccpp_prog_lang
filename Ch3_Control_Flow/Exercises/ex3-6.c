/*
 * Author   : Ciprian Manea
 * Date     : 08-03-2015
 * ----------------------------
 *  Write a version of itoa that accepts three arguments instead of two. 
 * The third argument is a minimum field width; the converted number must be
 * padded with blanks on the left if nexessary to make it wide enough.
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[], int min_w_field);

int main()
{
    char s[22];
    int n = 2748;

    itoa(n, s, 6);
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
void itoa(int n, char s[], int min_w_field)
{
    int i, sign, digit_nr;
    long long n_long = n;

    if ((sign = n) < 0)     /* record sign */
        n = -n;             /* make n positive */
    i = digit_nr = 0;
    do {                    /* generate digits in reverse order */
        s[i++] =  n % 10 + '0'; /* get next digit */
        digit_nr++;
    } while ((n /= 10) > 0);    /* delete it */
    if (sign < 0)
        s[i++] = '-';
    for (; i < min_w_field; i++)
        s[i] = ' ';
    s[i] = '\0';
    
    reverse(s);
}
