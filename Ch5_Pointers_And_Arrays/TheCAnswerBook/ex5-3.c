/*
 * Author   : Dennis M. Ritchie
 * Date     : 22-03-2015
 * ----------------------------
 *  Write a pointer version of the functio strcat that we showed
 * in Ch2: strcat(s, t) copies the string t to the end of s. 
 */

#include <stdio.h>

void mystrcat(char *s, char *t);

int main()
{
    char s[100] = "cine ";
    char t[] = "este la  mine?";
    
    mystrcat(s, t);
    printf("%s\n", s);

    return 0;
}

/* strcat: concatenate t to the end of s; pointer version */
void mystrcat(char *s, char *t)
{
    while (*s)
        s++;
    while (*s++ = *t++)
        ;
}
