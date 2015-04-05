/*
 * Author   : Dennis M. Ritchie
 * Date     : 31-03-2015
 * ----------------------------
 *  Implement a pattern-finding algorithm.
 */

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getLine(char line[], int max);

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int found = 0;

    if (argc != 2)
        printf("Usage: find pattern\n");
    else
        while (getLine(line, MAXLINE) > 0)
            if (strstr(line, argv[1]) != NULL) {
                printf("%s", line);
                found++;
            }

    return found;
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
