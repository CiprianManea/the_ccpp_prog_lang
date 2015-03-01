/*
 * Author   : Ciprian Manea
 * Date     : 25-02-2015
 * ------------------------
 *  Write a loop equivalent to the for loop above without using && or ||.
 */
#include <stdio.h>

#define STR_LEN 1000        /* defines the length of the string */

int main()
{
    int i, c, lim;
    char s[STR_LEN];

    lim = STR_LEN;
    for (i = 0; (c = getchar()) != '\n'; ++i) {
        if (i > lim-1)
            break;
        if (c == EOF)
            break;
        s[i] = c;
    }

    return 0;
}
