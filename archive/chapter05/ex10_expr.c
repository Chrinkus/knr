/*
 * Exercise 10
 *
 * Command line Reverse-Polish Calculator
 *
 * Write the program expr, which evaluates a reverse Polish expression from
 * the command line, where each operator or operand is a separate argument. For
 * example,
 *      $ ./expr 2 3 4 + *
 * evaluates 2 x (3 + 4).
 *
 * Had a funny error here that was tough to figure out. Entering * from the 
 * command line is treated as the wildcard so all the files in the current
 * directory are passed to the program. Probably had this same issue in the
 * chapter 4 Polish calculator questions.
 *
 * Anyway, to fix this I changed multiplication to 'x' and updated the usage
 * string to indicate this.
 */

#include <stdio.h>
#include <stdlib.h>         /* for atof() */

#define MAXOP   100         /* max size of operand or operator */
#define NUMBER  '0'         /* signal that a number was found */

int new_getop(char *in, char out[]);
void push(double);
double pop(void);

/* expr: command line argument reverse Polish calculator */
int main(int argc, char *argv[])
{
    int i, type;
    double op2;
    char s[MAXOP];

    if (argc < 2)
        printf("Usage: expr <reverse Polish expression(+-x/)>\n");
    else {
        // perform polish calculation!
        for (i = 1; i < argc; ++i) {
            type = new_getop(argv[i], s);
            switch (type) {
                case NUMBER:
                    push(atof(s));
                    break;
                case '+':
                    push(pop() + pop());
                    break;
                case 'x':
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
                default:
                    printf("error: unknown command %s\n", s);
                    break;
            }
        }
    }

    printf("\t%.8g\n", pop());

    return 0;
}

#define MAXVAL  100         /* maximum depth of val stack */

int sp = 0;                 /* next free stack position */
double val[MAXVAL];         /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from the stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>

/* new_getop: get operator or numeric operand from input string */
int new_getop(char *in, char out[])
{
    int i, c;

    while ((out[0] = c = *in++) == ' ' || c == '\t')
        ;
    out[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;           /* not a number */
    i = 0;
    if (isdigit(c))         /* collect integer part */
        while (isdigit(out[++i] = c = *in++))
            ;
    if (c == '.')           /* collect fraction part */
        while (isdigit(out[++i] = c = *in++))
            ;
    out[i] = '\0';
    return NUMBER;
}
