/*
 * Author   : Dennis M. Ritchie
 * Date     : 22-03-2015
 * ----------------------------
 *  Rewrite readlines to store lines in an array supplied by main, rather
 * than calling alloc to maintain storage. How much faster is the program?
 */

#include <stdio.h>
#include <string.h>

#define MAXLINES    5000        /* max #lines to be sorted */

char *lineptr[MAXLINES];        /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int ain()
{
    int nlines;     /* number of input lines read */

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN  1000        /* max length of any input line */
int getline(char *, int);
char *alloc(int);

/* readline: read input lines */
int readlines(char *lineptr[], char *linestor, int maxlines)
{
    int len, nlines;
    char *p = linestor, line[MAXLEN];
    char *linestorp = linestor + MAXSTOR;

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || p+len > linestop)
            return -1;
        else {
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += nlines;
        }
    return nlines;
}

/* writelines: write output lines V1*/
void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* writelines: write output lines V2*/
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
    int i, last;
    
    if (left >= right)      /* do nothing if array contains */
        return;             /* fewer that two elements */
    swap(v, left, (left + right / 2));
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) > 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap: interchage v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
