/*
 * Author   : Dennis M. Ritchie
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
    char *bs = s;           /* remember beginning of strs */
    char *bt = t;

    for (; *s; s++)         /* end of the string s */
        ;
    for (; *t; t++)         /* end of the string t */
        ;
    for (; *s == *t; s--, t--)
        if (t == bt || s == bs)
           break;           /* at the beginning of a str */
   if (*s == *t && t == bt && *s != '\0')
      return 1;
   else
      return 0; 
}
