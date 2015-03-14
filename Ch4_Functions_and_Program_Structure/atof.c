/*
 * Author   : Dennis M. Ritchie
 * Date     : 11-03-2015
 * ----------------------------
 *  Write a function that converts a string to a floating point number.
 * ----------------------------
 *  Structure:
 *      * skip white space, if any
 *      * get sign, if any
 *      * get integer part and convert it
 */

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

double atof(char s[]);
int getLine(char s[], int lim);

int main()
{
    double sum;
    char line[MAXLINE];

    sum = 0;
    while (getLine(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));

    return 0;
}

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
            val = 10.0 * val + (s[i] - '0');
            power *= 10.0;
    }
    return sign * val / power;
}

/* getline: get line into s, return length */
int getLine(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

