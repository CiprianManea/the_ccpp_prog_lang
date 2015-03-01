/*
 * Author   : Dennis M. Ritchie
 * Date     : 25-02-2015
 * ------------------------
 *  Write a loop equivalent to the for loop above without using && or ||.
 */
#include <stdio.h>

#define STR_SIZE    1000

enum loop{NO, YES};
enum loop okloop = YES;

int main()
{
    int i, c, lim;
    char s[STR_SIZE];

    i = 0;
    lim = STR_SIZE;
    while(okloop == YES)
        if (i >= lim-1)         /* outside of valid range? */
            okloop = NO;
        else if ((c = getchar()) == '\n')
            okloop = NO;
        else if (c == EOF)      /* enf of file? */
            okloop = NO;
        else {
            s[i] = c;
            ++i;
        }

    return 0;
}
