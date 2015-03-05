/*
 * Author   : Dennis M. Ritchie
 * Date     : 1-03-2015
 * ------------------------
 *  Write a function escape(s, t) that converts characters like newline and tab
 * into visible escape sequences like \n and \t as it copies the string t to s.
 * Use a switch. Write a function for the other direction as well, converting
 * escape sequences into the real characters.
 */

#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main()
{
    char s[15];
    char t[] = "test \t\tstring\n";
   
    escape(s, t); 
    printf("After escape: '%s'\n", s); 
    
    char p[] = "test \\t\\tstring\\n";
    unescape(s, p);
    printf("After escToChar: '%s'\n", s);

    return 0;
}

/* escape: expand newline and tab into sisible sequences 
 *         while copying the string t to s */
void escape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++, j++)
        switch(t[i]) {
            case '\n':              /* newline */
                s[j++] = '\\';
                s[j] = 'n';
                break;
            case '\t':              /* tab */
                s[j++] = '\\';
                s[j] = 't';
                break;
            default:                /* all other chars */
                s[j] = t[i];
        }
    s[j] = t[i];
}

/* escToChar: convert escap sequences into real characters
 *            while copying the string t to s */
void unescape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++, j++)
        if (t[i] != '\\')
            s[j++] = t[i];
        else                        /* if is a backslash */
            switch(t[++i]) {
                case 'n':           /* real newline */
                    s[j++] = '\n';
                    break;
                case 't':           /* real tab */
                    s[j++] = '\t';
                    break;
                default:            /* all other chars */
                    s[j++] = '\\';
                    s[j++] = t[i];
                    break;
            }
    s[j] = t[i];
}
