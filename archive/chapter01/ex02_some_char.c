/*
 * Exercise 1-2
 *
 * Experiment with different escaped characters in printf's argument string.
 *
 * Result is a warning for an unknown escape sequence.
 */

#include <stdio.h>

int main()
{
    printf("hello, world\m\n");     /* hello, worldm */
    printf("hello, world\w\n");     /* hello, worldw */
    printf("hello, world\q\n");     /* hello, worldq */
}
