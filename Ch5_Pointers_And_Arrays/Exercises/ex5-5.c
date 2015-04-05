/*
 * Author   : Ciprian Manea
 * Date     : 22-03-2015
 * ----------------------------
 *  Write versions of the library functions strncpy, strncat, and strncmp,
 * which operate on at most the first n characters of their argument string.
 * For example, strncpy(s, t, n) copies at most n characters of t to s.
 */

#include <stdio.h>

void mystrncpy(char *s, char *t, int n);
int mystrncmp(char *s, char *t, int n);

int main()
{
    int res;
    char s[100] = "minecarte";
    char t[] = "minemancare";
    
    res = mystrncmp(s, t, 4);
    printf("%d\n", res);

    return 0;
}

/* strncpy: copy the first n characters of t to s */
void mystrncpy(char *s, char *t, int n)
{
    while (n > 0 && (*s = *t)) {
        s++;
        t++;
        n--;
    }
    *s = '\0';
}

/* strncmp: returns <0 if s<t, 0 if s==t, >0 if s>t ; pointer version */
int mystrncmp(char *s, char *t, int n)
{
    for (; *s == *t && n > 0; s++, t++, n--)
        if (n == 1)
            return 0;
    return *s - *t;
}

/* strncat: copies the first n characters of string t to the end of s */
void mystrncat(char *s, char *t, int n)
{
    while (*s)
        s++;
    while ((*s++ = *t++) && n > 0)
        n--;
}

