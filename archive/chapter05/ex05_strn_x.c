/*
 * Exercise 5-5
 *
 * Write versions of the library functions my_strncpy, my_strncat, my_strncmp,
 * which operate on at most the first n characters of their argument strings.
 * For example, my_strncpy(s,t,n) copies at most n characters of t to s.
 */

#include <stdio.h>

#define BUFMAX 1000     /* max size char buffer */

char *my_strncpy(char *s, char *t, int n);
char *my_strncat(char *s, char *t, int n);
int   my_strncmp(char *s, char *t, int n);

int main()
{
    char b1[BUFMAX] = "Christmas";
    char b2[BUFMAX];
    char b3[BUFMAX] = "Merry ";
    int res;

    my_strncpy(b2, b1, 5);
    printf("Result of my_strncpy: %s\n", b2);

    my_strncat(b3, b1, 10);
    printf("Result of my_strncat: %s\n", b3);

    res = my_strncmp(b3, "Meriweather", 4);
    printf("Result of my_strncmp: %d\n", res);
}

char *my_strncpy(char *s, char *t, int n)
{
    while (n-- && (*s = *t) != '\0') {
        ++s;
        ++t;
    }
    return s;
}

char *my_strncat(char *s, char *t, int n)
{
    while (*s != '\0')
        ++s;
    while (n-- && (*s = *t) != '\0') {
        ++s;
        ++t;
    }
    return s;
}

int my_strncmp(char *s, char *t, int n)
{
    while (n-- && *t != '\0') {
        if (*s != *t)
            return *s - *t;
        ++s;
        ++t;
    }
    return 0;
}
