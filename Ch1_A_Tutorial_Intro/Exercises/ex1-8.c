/*
 * Author   : Ciprian Manea
 * Date     : 10-02-2015
 * ----------------------------
 * Count blanks, tabs and newlines.
 */
#include <stdio.h>

int main()
{
    int c, nb, nt, nl;

    nb = 0;
    nt = 0;
    nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++nb;
        else if (c == '\t')
            ++nt;
        else if (c == '\n')
            ++nl;
    }
    printf("nb = %d ; nt = %d ; nl = %d\n", nb, nt, nl);

    return 0;
}
