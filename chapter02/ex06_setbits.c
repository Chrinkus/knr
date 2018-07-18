/*
 * Exercise 2-6
 *
 * Write a function setbits(x,p,n,y) that returns x with the n bits that begin
 * at position p set to the rightmost n bits of y, leaving the other bits
 * unchanged.
 */

#include <stdio.h>
#include <math.h>

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y);

int main()
{
    unsigned x = 109;
    unsigned y = 26;

    printf("%d\n", setbits(x, 4, 3, y));
}

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y)
{
    unsigned xm = (x & ~(~(~0 << n) << (p + 1 - n)));
    unsigned ym = (y & ~(~0 << n)) << (p + 1 - n);

    return xm | ym;
}
