/*
 * Author   : Dennis M. Ritchie
 * Date     : 21-03-2015
 * ----------------------------
 *  As written, getint treats a + or - not followed by a digit as a valid
 * representation of zero. Fix it to push such a character back on the input.
 */

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))    /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);                 /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        d = c;                      /* remember sign char */
        if (!isdigit(c = getch())) {
            if (c != EOF)
                ungetch(c);         /* push back non-digit */
            ungetch(d);             /* push back sign char */
            return d;               /* return sign char */
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}
