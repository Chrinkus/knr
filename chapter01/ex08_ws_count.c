/*
 * Exercise 1-8
 *
 * Write a program to count blanks, tabs and newlines
 */

#include <stdio.h>

int main()
{
    int c,
        ns,         /* number of spaces */
        nt,         /* number of tabs */
        nl;         /* number of newlines */

    ns = 0;
    nt = 0;
    nl = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++ns;
        if (c == '\t')
            ++nt;
        if (c == '\n')
            ++nl;
    }

    printf("spaces: %d, tabs: %d, newlines: %d\n", ns, nt, nl);
}
