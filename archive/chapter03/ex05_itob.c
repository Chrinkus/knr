/*
 * Exercise 3-5
 *
 * Write the function itob(n,s,b) that converts the integer n into a base b
 * character representation in the string s. In particular, itob(n,s,16)
 * formats n as a hexadecimal integer in s.
 *
 * Not sure what would be the best solution for negative values since different
 * bases suggest a sign bit.
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_CHAR    128

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
    int x1 = 37;
    int x2 = -9;
    int x3 = 299792458;
    int x4 = INT_MIN;

    char res[MAX_CHAR];

    itob(x1, res, 2);
    printf("%d == %s\n", x1, res);

    itob(x1, res, 8);
    printf("%d == %s\n", x1, res);

    itob(x1, res, 16);
    printf("%d == %s\n", x1, res);

    itob(x2, res, 8);
    printf("%d == %s\n", x2, res);

    itob(x3, res, 16);
    printf("%d == %s\n", x3, res);

    itob(x4, res, 16);
    printf("%d == %s\n", x4, res);
}

void itob(int n, char s[], int b)
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;

    i = 0;
    do {
        int temp = n % b;
        s[i++] = (temp > 9)
            ? temp - 10 + 'A'
            : temp + '0';
    } while ((n /= b) > 0);

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
