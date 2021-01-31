/*
 * Exercise 5-2
 *
 * Write getfloat, the floating-point analog to getint. What type does getfloat
 * return as its function value?
 */

#include <stdio.h>

int getfloat(float *);

int main()
{
    float x;
    int res;

    while ((res = getfloat(&x)) != EOF)
        printf("%d was the result of getting %f\n", res, x);
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getfloat(float *pf)
{
    int c, peek;
    float sign, power;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1.0 : 1.0;

    if (c == '+' || c == '-') {
        if (!isdigit(peek = getch())) {
            ungetch(peek);
            ungetch(c);
            return 0;
        }
        else
            c = peek;
    }
    for (*pf = 0.0; isdigit(c); c = getch())
        *pf = 10.0 * *pf + (c - '0');
    if (c == '.')
        c = getch();
    for (power = 1.0; isdigit(c); c = getch()) {
        *pf = 10.0 * *pf + (c - '0');
        power *= 10.0;
    }
    *pf = sign * *pf / power;
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
