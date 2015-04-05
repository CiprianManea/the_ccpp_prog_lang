/*
 * Author   : Ciprian Manea
 * Date     : 01-04-2015
 * ------------------------
 *  Write the program expr, which evaluates a reverse Polish expression from
 * the command line, where each operator or operand is a separate argument.
 * For example: expr 2 3 4 + *  evaluates as 2 x (3 + 4)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int res = 0, op1;
    int nr_index = 0;
    char **nrIndex = argv;

    if (argc > 4) {
        while (isdigit((*++nrIndex)[0]))
            nr_index++;
        argv = nrIndex;
        *--nrIndex;

        res = atoi(*nrIndex--);
        nr_index--;
        while (nr_index) {
            op1 = atoi(*nrIndex--);
            nr_index--;
            switch ((*argv++)[0]) {
            case '+':
                res += op1;
                break;
            case '*':
                res *= op1;
                break;
            default:
                printf("Unknown operation!\n");
            }
        }
        printf("res = %d\n", res);
    } else
        printf("usage: expr 2 3 4 + * \n");

    return 0;
}
