/*
 * Exercise 5-1
 *
 * As written, getint treats a + or - not followed by a digit as a valid
 * representation of zero. Fix it to push such a character back onto the input.
 */

#include <stdio.h>

int getint(int *);

int main()
{
    int x1 = 7777;          /* should show up on input test for exercise */
    int res = getint(&x1);
    printf("%d was gotten resulting in %d\n", x1, res);
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign, peek;

    while (isspace(c = getch()))        /* skip whitespace */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);         /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {
        if (!isdigit(peek = getch())) {
            ungetch(peek);
            ungetch(c);
            return 0;
        }
        else
            c = peek;
    }

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
