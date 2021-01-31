/*
 * Exercise 5-6
 *
 * Rewrite appropriate programs from earlier chapters and exercises with
 * pointers instead of array indexing. Targets: getline, atoi, itoa, reverse,
 * strindex and getop(not done).
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 1000

int  my_getline(char *s, int max);
int  strindex(char *s, char *t);
void reverse(char *s);
int  atoi(char *s);
void itoa(int n, char *s);

int main()
{
    int len, pos;
    char line[MAXLINE], *s = "1234";

    while ((len = my_getline(line, MAXLINE)) > 0) {
        pos = strindex(line, "day");
        reverse(line);
        printf("length = %d, day @ %d, %s\n", len, pos, line);
    }

    printf("End of input reached\n");

    printf("%s * 2 = %d\n", s, atoi(s) * 2);
    itoa(37, line);
    printf("itoa test: %s\n", line);
}

int my_getline(char *s, int max)
{
    char *p = s;
    int c;

    while (--max > 0 && (c=getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - p;
}

int strindex(char *s, char *t)
{
    char *p, *q, *r;

    for (p = s; *p; ++p) {
        for (q = p, r = t; *r && *q == *r; ++q, ++r)
            ;
        if (r > t && !*r)
            return p - s;
    }
    return -1;
}

void reverse(char *s)
{
    char *t, c;

    for (t = s + strlen(s) - 1; s < t; ++s, --t) {
        c = *s;
        *s = *t;
        *t = c;
    }
}

int atoi(char *s)
{
    int n, sign;

    while (isspace(*s))
        ++s;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '-' || *s == '+')
        ++s;
    for (n = 0; isdigit(*s); ++s)
        n = 10 * n + (*s - '0');
    return sign * n;
}

void itoa(int n, char *s)
{
    int sign;
    char *p = s;

    if ((sign = n) < 0)
        n = -n;
    do {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    reverse(p);
}
