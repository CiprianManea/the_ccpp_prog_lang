/*
 * Author   : Ciprian Manea
 * Date     : 27-02-2015
 * ------------------------
 *  Writea an alternate version of squeeze(s1, s2) that deletes each character
 * in s1 that matches any character in the string s2.
 */

#include <stdio.h>

void squeeze(char s1[], const char s2[]);

int main()
{
    char s1[] = "Who is this boy, that I don't know?";
    char d[] = "oih";

    squeeze(s1, d);
    printf("Remained: %s\n", s1);

    return 0;
}

void squeeze(char s1[], const char s2[])
{
    int i, j, k;

    for (i = 0; s2[i] != '\0'; ++i) {
        for (k = j = 0; s1[j] != '\0'; ++j)
            if (s1[j] != s2[i])
                s1[k++] = s1[j];
        s1[k] = '\0';
    }
}
