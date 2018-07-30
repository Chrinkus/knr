/*
 * Exercise 4-12
 *
 * Adapt the ideas of printd to write a recursive version of itoa; that is,
 * convert an integer into a string by calling a recursive routine.
 */

#include <stdio.h>

#define MAXDIG  100         /* maximum number of digits to process */

void itoa(int, char [], int);

int main()
{
    int x1 = 37;
    int x2 = -9;
    int x3 = 0;
    int x4 = 299792458;
    int x5 = -12358;

    char s[MAXDIG];

    itoa(x1, s, 0);
    printf("%d == %s\n", x1, s);

    itoa(x2, s, 0);
    printf("%d == %s\n", x2, s);

    itoa(x3, s, 0);
    printf("%d == %s\n", x3, s);

    itoa(x4, s, 0);
    printf("%d == %s\n", x4, s);

    itoa(x5, s, 0);
    printf("%d == %s\n", x5, s);
}

void itoa(int n, char s[], int i)
{
    if (n < 0) {
        s[i++] = '-';
        n = -n;
    }
    if (n / 10)
        itoa(n / 10, s, i + 1);
    else
        s[i + 1] = '\0';
    s[i] = n % 10 + '0';
}
