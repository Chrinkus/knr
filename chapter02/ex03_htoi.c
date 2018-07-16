/*
 * Exercise 2-3
 *
 * Write the function htoi(s), which converts a string of hexadecimal digits
 * (including an optional 0x or 0X) into its equivalent integer value.
 */

#include <stdio.h>
#include <ctype.h>

int htoi(char s[]);

int main()
{
    char test[] = "0xfff";
    printf("%s = %d\n", test, htoi(test));
}

int htoi(char s[])
{
    int i, n;

    /* remove leading 0x or 0X */
    i = 0;
    if (s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X'))
        i += 2;

    for (n = 0; s[i] != '\0'; ++i) {
        int val;
        if (isdigit(s[i]))
            val = s[i] - '0';
        else if ('A' <= s[i] && s[i] <= 'F')
            val = 10 + s[i] - 'A';
        else if ('a' <= s[i] && s[i] <= 'f')
            val = 10 + s[i] - 'a';
        else {
            printf("%s is not a hexadecimal value\n", s);
            return 0;
        }

        n = 16 * n + val;
    }
    return n;
}
