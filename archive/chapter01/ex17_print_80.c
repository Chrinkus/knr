/*
 * Exercise 1-17
 *
 * Write a program to print all input lines that are longer than 80 characters.
 */

#include <stdio.h>

#define CHAR_BREAK 80   /* character breakpoint to start printing */

int my_getline(char line[], int max);
void flush_input(void);

int main()
{
    int len;
    char line[CHAR_BREAK];

    while ((len = my_getline(line, CHAR_BREAK)) > 0) {
        if (len == CHAR_BREAK - 1 && line[len - 1] != '\n') {
            printf("%s", line);
            flush_input();
        }
    }
}

int my_getline(char line[], int max)
{
    int c, i;

    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    line[i] = '\0';

    return i;
}

void flush_input()
{
    int c;
    while ((c = getchar()) != EOF && c != '\n')
        putchar(c);
    putchar('\n');
}
