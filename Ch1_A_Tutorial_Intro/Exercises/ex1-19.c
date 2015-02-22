/*
 * Author:  Ciprian Manea
 * Date:    22-02-2015
 * --------------------------
 *  Write a function reverse(s) that reverses the character string s.
 * Use it to write a program that reverses its input a line at a time.
 */
#include <stdio.h>

#define MAXLINE     1000    /* maximum input line size */

int getLine(char s[], int lim);
void reverse(char s[]);

int main()
{
    int len;            /* current line length */
    int pos;            /* index position to copy next line. */
    char line[MAXLINE];     /* current input line */

    pos = 0;
    while ((len = getLine(line, MAXLINE)) > 0) {
        reverse(line);
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

/* reverse: will reverse the character string s. */
void reverse(char s[])
{
    int i, j;
    char tmp;

    i = j = 0;
    while (s[i] != '\n')    /* search end of string. */
        ++i;
    --i;                    /* get rid of new line character. */

    if (i > 1) {
        while (j != i) {
            tmp = s[j];
            s[j] = s[i];
            s[i] = tmp;
            j++;
            i--;
        }
    }
}
