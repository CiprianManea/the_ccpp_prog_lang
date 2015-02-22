/*
 * Author   : Ciprian Manea
 * Date     : 22-02-2015
 * ------------------------
 *  Write a program detab that replaces tabs in the input with the
 * proper number of blanks to space to the next tab stop. Assume a fixed
 * set of tab stops, say every 'n' columns. Should 'n' be a variable or 
 * a symbolic parameter?
 * ------------------------
 *  A: 'n' should be a symbolic parameter
 */
#include <stdio.h>

#define TAB_SIZE    2   /* tab will be replace by 2 spaces */

int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar(' ');
            putchar(' ');
        } else {
            putchar(c);
        }
    }

    return 0;
}
