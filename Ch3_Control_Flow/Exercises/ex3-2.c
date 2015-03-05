/*
 * Author   : Ciprian Manea
 * Date     : 1-03-2015
 * ------------------------
 *  Write a function escape(s, t) that converts characters like newline and tab
 * into visible escape sequences like \n and \t as it copies the string t to s.
 * Use a switch. Write a function for the other direction as well, converting
 * escape sequences into the real characters.
 */

#include <stdio.h>

void escape(char s[], char t[]);
void escToChar(char s[], char t[]);

int main()
{
    char s[15];
    char t[] = "test \t\tstring\n";
   
    escape(s, t); 
    printf("After escape: '%s'\n", s); 
    
    char p[] = "test \\t\\tstring\\n";
    escToChar(s, p);
    printf("After escToChar: '%s'\n", s);

    return 0;
}

/* escape:  copies t[] in s[] and replaces newline and tab chars with visible chars */
void escape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++, j++) {
        switch(t[i]) {
            case '\t':
                s[j++] = '\\';
                s[j] = 't';
                break;
            case '\n':
                s[j++] = '\\';
                s[j] = 'n';
                break;
            default:
                s[j] = t[i];
        }
    }
    s[j] = t[i];
}

/* escToChar: copies t[] in s[] and replace newline and tab escape sequence to the real chars */
void escToChar(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++, j++) {
        if (t[i] == '\\' && t[i + 1] == 't') {
            s[j] = '\t';
            i++;
        } else if (t[i] == '\\' && t[i + 1] == 'n') {
            s[j] = '\n';
            i++;
        } else
            s[j] = t[i];
    }
    s[j] = t[i];
}
