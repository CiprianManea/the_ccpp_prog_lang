/*
 * Author   : Dennis M. Ritchie
 * Date     : 1-03-2015
 * ----------------------------
 *  Write a function that converts a string to integer.
 * ----------------------------
 *  Structure:
 *      * skip white space, if any
 *      * get sign, if any
 *      * get integer part and convert it
 */

#include <stdio.h>
#include <ctype.h>

int atoi(char s[]);

int main()
{
    char s[] = "  -1992";

    printf("%s result of 'atoi' : %d\n", s, atoi(s));

    return 0;
}

/* atoi: converts s to integer; version2 */
int atoi(char s[])
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') /* skip sign */
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}
