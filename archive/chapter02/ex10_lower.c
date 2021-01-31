/*
 * Exercise 2-10
 *
 * Rewrite the function lower, which converts upper case letters to lower case,
 * with a conditional expression instead of if-else.
 */

#include <stdio.h>

int lower(int c);

int main()
{
    int i;
    char s1[] = "This ShouLd aLL be LOwer CaSE";

    for (i = 0; s1[i] != '\0'; ++i)
        s1[i] = lower(s1[i]);

    printf("%s\n", s1);
}

int lower(int c)
{
    return ('A' <= c && c <= 'Z') ? c + 'a' - 'A' : c;
}
