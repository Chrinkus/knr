/*
 * Exercise 4-2
 *
 * Extend atof to handle scientific notation of the form 123.45e-6 where a
 * floating-point number may be followed by e or E and an optionally signed
 * exponent.
 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 100

/* rudimentary calculator */
int main()
{
    double sum, atof(char []);
    char line[MAXLINE];
    int my_getline(char line[], int max);

    sum = 0;
    while (my_getline(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    return 0;
}

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power, e_val;
    int i, sign;

    for (i = 0; isspace(s[i]); ++i)     /* skip whitespace */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    for (val = 0.0; isdigit(s[i]); ++i)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        ++i;
    for (power = 1.0; isdigit(s[i]); ++i) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    e_val = 1;
    if (s[i] == 'e' || s[i] == 'E') {
        e_val = atof(&s[++i]);
    }

    return pow(sign * val / power, e_val);
}

/* my_getline: get line into s, return length */
int my_getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
