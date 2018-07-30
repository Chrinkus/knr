/*
 * Exercise 4-13
 *
 * Write a recursive version of the function reverse(s), which reverses the
 * string s in place;
 */

#include <stdio.h>
#include <string.h>

void reverse(char [], int, int);

int main()
{
    char s1[] = "reverse";
    char s2[] = "redrum";

    reverse(s1, 0, strlen(s1) - 1);
    printf("%s\n", s1);

    reverse(s2, 0, strlen(s2) - 1);
    printf("%s\n", s2);
}

void reverse(char s[], int i, int j)
{
    int t;

    if (i >= j)
        return;

    t = s[i];
    s[i] = s[j];
    s[j] = t;

    reverse(s, ++i, --j);
}
