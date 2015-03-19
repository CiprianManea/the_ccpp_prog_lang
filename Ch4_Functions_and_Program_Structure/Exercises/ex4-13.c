/*
 * Author   : Ciprian Manea
 * Date     : 19-03-2015
 * ------------------------
 *  Write a recursive version of the function reverse(s), which
 * reverses the string s in place.
 */

#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main()
{
    char s[] = "alibaba";

    reverse(s);
    printf("reversed s: %s\n", s);

    return 0;
}

void reverse(char s[])
{
    int tmp;
    static int i = 0;
    static int j = sizeof(s);

    printf("i = %d  ; j = %d  \n", i, j);

    if (sizeof(s) <= 1)
        return;
    while (i < j) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
        reverse(s);
    }
}
