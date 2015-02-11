/*
 * Author   : Ciprian Manea
 * Date     : 11-02-2015
 * ----------------------------
 * Write a program to copy its input to its output,
 * replacing each string of one or more blanks by a single blank.
 */
#include <stdio.h>

int main()
{
    int c, isBlank;

    isBlank = 0;

    while ((c = getchar()) != EOF) {
        if ((c == ' ') && (isBlank == 0)) {
            putchar(c);
            isBlank = 1;
        } else if (c != ' ') {
            putchar(c);
            isBlank = 0;
        } 
    }

    return 0;
}
