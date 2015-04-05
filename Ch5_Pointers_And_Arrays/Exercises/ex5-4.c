/*
 * Author   : Ciprian Manea
 * Date     : 22-03-2015
 * ----------------------------
 *  Write the function strend(s, t), which returns 1 if the string t 
 * occurs at the end of the string s, and zero otherwise. 
 */

#include <stdio.h>

int mystrend(char *s, char *t);

int main()
{
    char s[100] = "cine la mine";
    char t[] = "mlne";
    
    printf("strend? %s\n", mystrend(s, t) ? "true" : "false");

    return 0;
}

/* strend: returns 1 if the string t occurs at the end of string s, and zero otherwise */
int mystrend(char *s, char *t)
{
    int i = 0;

    while (*s)
        s++;
    while (*t) {
        t++;
        i++;
    }

    while (i >= 0) {
        if (*t-- != *s--)
            return 0;
        i--;
    }
    return 1;
}
