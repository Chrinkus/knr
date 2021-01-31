/*
 * Exercise 1-18
 *
 * Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete entirely blank lines.
 */

#include <stdio.h>

#define MAXCHAR 280     /* the maximum length of string acceptable */

int my_getline(char s[], int max);
void trim(char s[], int len);

int main()
{
    int len;
    char line[MAXCHAR];

    while ((len = my_getline(line, MAXCHAR)) > 0) {
        int l = 0;

        trim(line, len);

        while (line[l] != '\0') ++l;        /* get after-trim len */
        printf("%d (%d): %s\n", l, len, line);
    }
}

int my_getline(char s[], int max)
{
    int c, i;

    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

void trim(char s[], int len)
{
    char c;
    --len;                  /* skip null char */

    for (c = s[len]; len >= 0 && (c == '\n' || c == '\t' || c == ' ');
            c = s[--len]) {
        s[len] = '\0';
    }
}
