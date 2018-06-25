/*
 * Exercise 1-6
 *
 * Verify that the expression getchar() != EOF is 0 or 1
 */

#include <stdio.h>

int main()
{
    int c;

    printf("%d\n", (c = getchar()) != EOF);
}
