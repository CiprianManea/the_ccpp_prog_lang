/*
 * Author   : Dennis M. Ritchie
 * Date     : 31-03-2015
 * ----------------------------
 *  Implement the echo shell command. V2
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

    while (--argc > 0)
        printf("%s%s", *++argv, (argc > 1) ? " " : "");
    printf("\n");

    return 0;
}
