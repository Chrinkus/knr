/*
 * Exercise 3-6
 *
 * Write a version of itoa that accepts three arguments instead of two. The
 * third argument is a minimum field width; the converted number must be padded
 * with blanks on the left if necessary to make it wide enough.
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_CHAR    128

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main()
{
    char res[MAX_CHAR];

    int x1 = 37;
    int x2 = -10977312;
    int x3 = 65535;

    itoa(x1, res, 6);
    printf("%d = %s\n", x1, res);

    itoa(x2, res, 10);
    printf("%d = %s\n", x2, res);

    itoa(x3, res, 4);
    printf("%d = %s\n", x3, res);
}

void itoa(int n, char s[], int w)
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;

    i = 0;
    do {
        s[i++] = n % 10 + '0';
        --w;                    /* keep track of digit count */
    } while ((n /= 10) > 0);

    while (w-- > 0)             /* if digit padding is still needed */
        s[i++] = '0';

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
