/*
 * Exercise 1-16
 *
 * Revise the main routine of the longest line program so it will correctly
 * print the length of arbitrarily long input lines, and as much as possible of
 * the text.
 */

#include <stdio.h>

#define MAXLINE 10      /* maximum input line size */

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = my_getline(line, MAXLINE)) > 0)
        printf("%d: %s\n", len, line);

    return 0;
}

int my_getline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    while (c != EOF && c != '\n') {
        ++i;
        c = getchar();
    }

    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
