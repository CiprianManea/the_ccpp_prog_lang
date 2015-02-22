/*
 * Author:  Ciprian Manea
 * Date:    22-02-2015
 * --------------------------
 *  Write a program to print all input lines that are longer than 80 characters.
 */
#include <stdio.h>

#define MAXLINE     1000    /* maximum input line size */
#define ALL_LINES   10000   /* storage size for all lines over 80 ch. */
#define ACCEPTED_LINES  80  /* only lines that are over 80 ch. long will be storred */

int getLine(char line[], int maxline);
int copy(char to[], char from[], int pos);

int main()
{
    int len;            /* current line length */
    int pos;            /* index position to copy next line. */
    char line[MAXLINE];     /* current input line */
    char linesStorage[ALL_LINES];  /* storage for lines over 80 ch. */

    pos = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
        if (len > ACCEPTED_LINES) {
            pos = copy(linesStorage, line, pos);
        }

    if (pos > 0) {   /* there was a line */
        printf("%s", linesStorage);
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

/* copy: copy 'from' into 'to'; assume to is big enough */
int copy(char to[], char from[], int pos)
{
    int i;

    i = 0;
    while ((to[pos] = from[i]) != '\0') {
        ++pos;
        ++i;
    }

    return pos;
}
