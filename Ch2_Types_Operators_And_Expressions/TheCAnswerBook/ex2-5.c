/*
 * Author   : Dennis M. Ritchie
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
    int i, j;

    for (i = 0; s1[i] != '\0'; i++)
        for (j = 0; s2[j] != '\0'; j++)
            if (s1[i] == s2[j])         /* match found? */
                return 1;               /* location first match */
    return -1;                          /* otherwise, no match */
}
