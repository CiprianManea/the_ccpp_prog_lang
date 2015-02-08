/*
 * Author   : Dennis M. Ritchie
 * Date     : 08-02-2015
 * ----------------------------
 * Copy input to output; 1st version.
 */
#include <stdio.h>

int main()
{
    int c;

    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }

    return 0;
}
