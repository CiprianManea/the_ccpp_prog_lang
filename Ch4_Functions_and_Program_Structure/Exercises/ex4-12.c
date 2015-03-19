/*
 * Author   : Ciprian Manea
 * Date     : 19-03-2015
 * ------------------------
 *  Adapt the ideas of printd to write a recursive version of itoa;
 * this is, convert an integer into a string by calling a recursive routine.
 */

#include <stdio.h>

#define MAX_SIZE    100

void itoA(int n, char s[]);
static int i = 0;

int main()
{
    char s[MAX_SIZE];
    int n = 1234;

    itoA(n, s);
    s[i] = '\0';
    printf("nr = %s\n", s);
    
    return 0;
}

/* itoa: converts an integet to a char using a recursive method */
void itoA(int n, char s[])
{
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        itoA(n / 10, s);
    s[i++] = n % 10 + '0';
}
