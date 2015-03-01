/*
 * Author   : Dennis M. Ritchie
 * Date     : 28-02-2015
 * ------------------------
 *  Rewrite the function lower, which converts upper case letters
 *  to lower case, with a conditional expression instead of if-else.
 */

#include <stdio.h>

int lower(int c);

int main()
{
    printf("lower case 'A' is: %c\n", lower('A'));

    return 0;
}

/* lower: converts c to lower case (ASCII only) */
int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c;
}
