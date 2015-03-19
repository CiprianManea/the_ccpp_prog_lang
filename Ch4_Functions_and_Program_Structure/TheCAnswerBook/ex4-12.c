/*
 * Author   : Dennis M. Ritchie
 * Date     : 19-03-2015
 * ------------------------
 *  Adapt the ideas of printd to write a recursive version of itoa;
 * this is, convert an integer into a string by calling a recursive routine.
 */

#include <stdio.h>

#define MAX_SIZE    100

void itoA(int n, char s[]);

int main()
{
    char s[MAX_SIZE];
    int n = 1234;

    itoA(n, s);
    printf("nr = %s\n", s);
    
    return 0;
}

/* itoa: convert n to characters in s; recursive*/
void itoA(int n, char s[])
{
    static int i;

    if (n / 10) 
        itoA(n / 10, s);
    else {
        i = 0;
        if (n < 0)
            s[i++] = '-';
    }
    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';
}
