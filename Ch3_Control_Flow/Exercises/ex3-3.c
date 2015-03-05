/*
 * Author   : Ciprian Manea
 * Date     : 1-03-2015
 * ------------------------
 *  Write a function expand(s1, s2) that expands shorthand notation like a-z
 * in the string s1 into the equivalent complete list abc...xyz in s2. Allow
 * for letters of either case and digits, and be prepared to handle cases 
 * like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is
 * taken literally.
 */

#include <stdio.h>
#include <ctype.h>

void expand(char s1[], char s2[]);

int main()
{
    char s1[] = "My str a-p miau 0-7 -a-e a-b-c!";
    char s2[100];

    expand(s1, s2);
    printf("Expanded string: %s\n", s2);

    return 0;
}

/* expand: expands shorthand notation like a-z in the string s1 into the
 *          equivalent complete list abc...xyz in s2. */
void expand(char s1[], char s2[])
{
    int i, j, k;

    for (i = j = 0; s1[i] != 0; i++, j++) {
        if (isalnum(s1[i])) {
            if (s1[i + 1] == '-') {
                if (isalnum(s1[i + 2])) {
                    for (k = s1[i]; k <= s1[i + 2]; k++) {
                        s2[j++] = k;
                    }
                    j--;
                    i += 2;
                } else {
                    s2[j] = s1[i];
                }
            } else {    
                s2[j] = s1[i];
            }
        } else {
            s2[j] = s1[i];
        }
    }
    s2[j] = s1[i];
}
