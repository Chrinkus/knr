/*
 * Exercise 5-4
 *
 * Write the function strend(s,t), which returns 1 if the string t occurs at
 * the end of the string s, and zero otherwise.
 */

#include <stdio.h>

int strend(char *s, char *t);

int main()
{
    char *s1 = "Christmas";
    char *s2 = "tmas";
    char *s3 = "istma";

    if (strend(s1, s2))
        printf("%s ends with %s\n", s1, s2);
    else
        printf("no match\n");

    if (strend(s1, s3))
        printf("%s ends with %s\n", s1, s3);
    else
        printf("no match\n");
}

int strend(char *s, char *t)
{
    char *p = t;

    while (*s != '\0')
        ++s;
    while (*t != '\0')
        ++t;
    while (t != p)
        if (*s-- != *t--)
            return 0;
    return 1;
}
