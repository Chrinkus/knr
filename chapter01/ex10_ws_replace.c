/*
 * Exercise 1-10
 *
 * Write a program to copy its input to its output, replacing each tab by \t,
 * each backspace by \b, and each backslash by \\.
 *
 * Do people actually 'type' backspace?
 */

#include <stdio.h>

int main()
{
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            c = 't';
        }
        if (c == '\b') {
            putchar('\\');
            c = 'b';
        }
        if (c == '\\') {
            putchar('\\');
            c = '\\';
        }
        putchar(c);
    }
}
