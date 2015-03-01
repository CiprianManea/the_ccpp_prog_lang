/*
 * Author   : Ciprian Manea
 * Date     : 27-02-2015
 * ------------------------
 *  Write a function any(s1, s2), which returns the first location in the string s1 where
 * any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
 * (The standard library function strpbrk does the same job but returns a pointer to
 * the location.)
 */

#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{
    char s1[] = "first string";
    char s2[] = "xxsecond";

    printf("Matching location of str1 with str2 = %d", any(s1, s2));

    return 0;
}

int any(char s1[], char s2[])
{
    int i, j, loc;

    loc = -1;
    for (i = 0; s2[i] != '\0'; i++) {
        for (j = 0; s1[j] != '\0'; j++)
            if (s1[j] == s2[i])
                loc = j;
        if (loc >= 0)
            break;
    }

    return loc;
}
