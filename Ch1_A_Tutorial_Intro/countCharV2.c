/*
 * Author   : Dennis M. Ritchie
 * Date     : 10-02-2015
 * ----------------------------
 * Count characters in input; 2st version.
 */
#include <stdio.h>

int main()
{
    double nc;

    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);

    return 0;
}
