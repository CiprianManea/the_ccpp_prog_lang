/*
 * Author   : Ciprian Manea
 * Date     : 22-02-2015
 * ------------------------
 *  Write a program to "fold"  long input lines into two or more shorter lines
 * after the last non-blank character that occurs before the n-th column of input.
 * Make sure your program does something intelligent with very long lines, and if
 * there are no blanks or tabs before the specifed column.
 */
#include <stdio.h>

#define LINE_LEN    20      /* split line at */

int main()
{
    int c, cnt;

    cnt = 0;
    while ((c = getchar()) != EOF) {
        ++cnt;
        if (c == '\n' || c == '\0') {
            cnt = 0;
            putchar(c);
        }
        else if (cnt > LINE_LEN  && (c == ' ' || c == '\t')) {
           putchar('\n');
           cnt = 0;
        } else 
            putchar(c);
    }

    return 0;
}
