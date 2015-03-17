/*
 * Author   : Dennis M. Ritchie
 * Date     : 15-03-2015
 * ----------------------------
 *  Add access to library functions like sin, exp, and pow. See <math.h> in
 * Appendix B, Section 4.
 */

#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <ctype.h>

#define MAXOP   100     /* max size of operand or operator */
#define NUMBER  '0'     /* signal that a number was found */
#define NAME    'n'     /* signal that a name was found */

int getop(char []);
void push(double);
double pop(void);
void clear(void);
void mathfnc(char []);

int main()
{
    int type;
    double op1, op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                printf("look a nr\n");
                push(atof(s));
                break;
            case NAME:
                mathfnc(s);
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
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push((int)pop() % (int)op2);
                else
                    printf("error: zero division\n");
                break;
            case '?':   /* print top element of the stack */
                op2 = pop();
                printf("\t%.8g\n", op2);
                push(op2);
                break;
            case 'c':   /* clear the stack */
                clear();
                break;
            case 'd':   /* duplicate top elem. of the stack */
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case 's':   /* swap the top two elements */
                op1 = pop();
                op2 = pop();
                push(op1);
                push(op2);
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

/* mathfnc: check string s for supported math functions */
void mathfnc(char s[])
{
    double op2;

    if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s, "pow") == 0) {
        op2 = pop();
        push(pow(pop(), op2));
    } else
        printf("error: %s not supported\n", s);
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

/* clear: clear the stack */
void clear(void)
{
    sp = 0;
}

int getch(void);
void ungetch(int);

/* getop: get next operator or numberic operand, or math fnc */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if (islower(c)) {       /* command or NAME */
        while (islower(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);     /* went one char too far */
        if (strlen(s) > 1)
            return NAME;    /* >1 char; it is NAME */
        else
            return c        /* it may be a command */
    }

    if (!isdigit(c) && c != '.' && c != '-')
        return c;           /* not a number */
    if (c == '-')
        if (isdigit(c = getch()) || c == '.')
            s[++i] = c;     /* negative number */
        else {
            if (c != EOF)
                ungetch(c);
            return '-';     /* return sign */      
        }
    if (isdigit(c))     /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')       /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int getch(void)     /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
