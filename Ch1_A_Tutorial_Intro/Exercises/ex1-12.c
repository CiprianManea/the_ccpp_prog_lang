/*
 * Author   : Ciprian Manea
 * Date     : 12-02-2015
 * ----------------------------
 * Write a program that prints its input one word per line.
 */
#include <stdio.h>

#define IN  1   /* inside a word */
#define OUT 0   /* outside a word */

int main()
{
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            state = IN;
            putchar(c);
        } else if (state == IN) {
            putchar('\n');
            state = OUT;
        }
    }

    return 0;
}
