/*
 * Exercise 3-4
 *
 * In a two's complement number representation, our version of itoa does not
 * handle the largest negative number, that is, the value of n equal to
 * -(2^wordsize-1). Explain why not. Modify it to print that value correctly,
 * regardless of the machine on which it runs.
 *
 * Explanation: two's complement integers can reach a negative value of 1
 * greater magnitude than they can reach positively. For example: a signed char
 * can range from -128:+127.
 *
 * When the text's itoa detects a negative value it stores the sign and
 * converts the value to positive which in the extreme negative case causes n
 * to remain the negative value it was. Modulo 10 + '0' of n walks back the 
 * character code to left paren '('. The subsequent check of n/=10 > 0 returns
 * false since the n is still a very negative value.
 * 
 * I thought of abs(n % 10) as a solution but that would call an extra function
 * every iteration through the loop so instead decided to take care of the one
 * special case in the sign assignment check.
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_CHAR    128

void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
    int x1 = INT_MIN;
    int x2 = -6;
    int x3 = 37;
    char s1[MAX_CHAR];

    itoa(x1, s1);
    printf("%d == %s\n", x1, s1);

    itoa(x2, s1);
    printf("%d == %s\n", x2, s1);

    itoa(x3, s1);
    printf("%d == %s\n", x3, s1);
}

void itoa(int n, char s[])
    /* not an elegant solution to INT_MIN scenario */
{
    int i, sign;

    i = 0;
    if ((sign = n) < 0) {       /* record the sign */
        if (n < -10) {
            s[i++] = -(n % 10) + '0';
            n /= 10;
        }
        n = -n;                 /* make n positive */
    }

    do {                        /* generates digits in reverse order */
        s[i++] = n % 10 + '0';  /* get next digit */
    } while ((n /= 10) > 0);    /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
