/*
 * Exercise 1-9
 *
 * Write a program to copy its input to its output, replacing each string of
 * one or more spaces with a single space.
 */

#include <stdio.h>

main()
{
    int c, ns;

    ns = 0;
    while ((c = getchar()) != EOF) {
        if (c != ' ')
            ns = 0;
        if (ns == 0)
            putchar(c);
        if (c == ' ')
            ++ns;
    }
}
