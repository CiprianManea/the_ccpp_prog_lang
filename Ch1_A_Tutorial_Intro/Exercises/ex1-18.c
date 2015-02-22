/*
 * Author:  Ciprian Manea
 * Date:    22-02-2015
 * --------------------------
 *  Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete entirely blank lines.
 */
#include <stdio.h>

#define MAXLINE     1000    /* maximum input line size */
#define ALL_LINES   10000   /* storage size for all lines over 80 ch. */

int getLine(char s[], int lim);
int cleanLine(char line[], int size);

int main()
{
    int len;            /* current line length */
    int pos;            /* index position to copy next line. */
    char line[MAXLINE];     /* current input line */

    pos = 0;
    while ((len = getLine(line, MAXLINE)) > 0) {
        pos = cleanLine(line, len);
        if (pos > 0)
            printf("%s", line);
    }
    
    return 0;
}

/* getline: read a line into s, return length */
int getLine(char s[], int lim)
{
    int c, i, maxLineIndex;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim-1) {
            s[i] = c;
            maxLineIndex = i;
        }
    }
    ++maxLineIndex;

    if (c == '\n') {
        s[maxLineIndex] = c;
        ++maxLineIndex;
    }
    s[maxLineIndex] = '\0';

    return i;
}

int cleanLine(char line[], int size)
{
    size -= 2;

    while (size > 0 && (line[size] == ' ' || line[size] == '\t')) {
        size--;
    }
    size++;

    line[size++] = '*';
    line[size++] = '\n';
    line[size] = '\0';
    
    return size;
}
