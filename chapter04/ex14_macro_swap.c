/*
 * Exercise 4-14
 *
 * Define a macro swap(t, x, y) that interchanges two arguments of type t.
 */

#include <stdio.h>

#define swap(t, x, y) (t = (x), x = (y), y = (t))

int main()
{
    int i;
    int ai[] = { 1, 2, 3, 4, 5, 6 };

    char a, b = 'b', c = 'c';

    swap(i, ai[0], ai[2]);

    for (i = 0; i < 6; ++i)
        printf("%d\n", ai[i]);

    swap(a, b, c);
    putchar(b);
    putchar(' ');
    putchar(c);
    putchar('\n');
}
