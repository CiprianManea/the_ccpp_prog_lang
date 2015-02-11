/*
 * Author   : Dennis M. Ritchie
 * Date     : 11-02-2015
 * ----------------------------
 * Write a program to count blanks, tabs and newlines.
 */
#include <stdio.h>

int main()
{
    int c, nb, nt, nl;

    nb = 0;     /* numbers of blanks */
    nt = 0;     /* number of tabs */
    nl = 0;     /* number of newlines */
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++nb;
        else if (c == '\t')
            ++nt;
        else if (c == '\n')
            ++nl;
    }
    printf("%d %d %d\n", nb, nt, nl);

    return 0;
}
