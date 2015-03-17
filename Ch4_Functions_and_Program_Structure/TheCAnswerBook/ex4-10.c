/*
 * Author   : Dennis M. Ritchie
 * Date     : 17-03-2015
 * ----------------------------
 *  An alternate organisation uses getline to read an entire input line;
 * this makes getch and ungetch unnecessary. Revise the calculator to use
 * this approach.
 */

#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <ctype.h>

#define MAXOP   100     /* max size of operand or operator */
#define NUMBER  '0'     /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                printf("look a nr\n");
                push(atof(s));
                break;
            case '+':
                printf("and a +\n");
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else 
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }

    return 0;
}

#define MAXVAL  100     /* maximum depth of val stack */

int sp = 0;             /* next free stack position */
double val[MAXVAL];     /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#define MAXLINE 100#define MAXLINE  100#define MAXLINE  100

int li = 0;             /* input line index */
char line[MAXLINE];     /* one input line */

/* getop: get next operator or numberic operand */
int getop(char s[])
{
    int i, c;

    if (line[i] == '\0')
        if (getline(line, MAXLINE) == 0)
            return EOF;
        else
            li = 0;
    while ((s[0] = c = line(li++)) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;       /* not a number */
    i = 0;
    if (isdigit(c))     /* collect integer part */
        while (isdigit(s[++i] = c = line(li++)))
            ;
    if (c == '.')       /* collect fraction part */
        while (isdigit(s[++i] = c = line(li++)))
            ;
    s[i] = '\0';
    li--;
    return NUMBER;
}
