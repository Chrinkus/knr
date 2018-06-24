/*
 * Exercise 1-12
 *
 * Write a program that prints its input one word per line.
 */

#include <stdio.h>

#define IN  1       /* inside word */
#define OUT 0       /* outside word */

main()
{
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                state = OUT;
                putchar('\n');
            }
        }
        else {
            putchar(c);
            if (state == OUT)
                state = IN;
        }
    }
}
