/*
 * Exercise 4-14
 *
 * Define a macro swap(t, x, y) that interchanges two arguments of type t.
 */

#include <stdio.h>

#define swap(t, x, y) { t z = x; x = y; y = z; }

int main()
{
    int a, b, i;
    double pi, e;

    int ai[] = { 1, 2, 3, 5, 8, 13, 21, 34 };

    a = 37;
    b = 42;
    swap(int, a, b);
    printf("a == %d, b == %d\n", a, b);

    pi = 3.14;
    e = 2.72;
    swap(double, pi, e);
    printf("pi == %g, e == %g\n", pi, e);

    swap(int, ai[1], ai[5]);
    for (i = 0; i < 8; ++i)
        printf("%d\n", ai[i]);
}
