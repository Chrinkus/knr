/*
 * Exercise 2-7
 *
 * Write a function invert(x,p,n) that returns x with the n bits that begin
 * at position p inverted, leaving the others unchanged.
 */

#include <stdio.h>

unsigned invert(unsigned x, unsigned p, unsigned n);

int main()
{
    unsigned x1 = 15;
    unsigned x2 = 10;
    unsigned x3 = 99;

    printf("%d\n", invert(x1, 2, 1));
    printf("%d\n", invert(x2, 1, 2));
    printf("%d\n", invert(x3, 7, 8));
}

unsigned invert(unsigned x, unsigned p, unsigned n)
{

    return (x&~(~(~0<<n)<<(p+1-n))) | (((~x>>(p+1-n))&~(~0<<n))<<(p+1-n));
}
