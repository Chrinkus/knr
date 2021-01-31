/*
 * Exercise 2-2
 *
 * Write a loop equivalent to the getline() loop without using && and ||.
 */

#include <stdio.h>

#define MAX_CHAR 280

int my_getline(char s[], int max);
int awk_getline(char s[], int max);

int main()
{
    int len;
    char line[MAX_CHAR];

    while ((len = awk_getline(line, MAX_CHAR)) > 0)
        printf("%s\n", line);
}

int my_getline(char s[], int max)
{
    int i, c;

    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}

int awk_getline(char s[], int max)
{
    int i, c;

    for (i = 0; i < max - 1; ++i) {
        if ((c = getchar()) == EOF) {
            s[i] = '\0';
            return i;
        }
        s[i] = c;
        if (c == '\n') {
            s[++i] = '\0';
            return i;
        }
    }
    s[i] = '\0';
    return i;
}
