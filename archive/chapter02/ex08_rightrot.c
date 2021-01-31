/*
 * Exercise 2-8
 *
 * Write a function rightrot(x,n) that returns the value of the integer x
 * rotated to the right by n bit positions.
 */

#include <stdio.h>

unsigned char rightrot(unsigned char x, unsigned n);

int main()
{
    unsigned char x1 = 99;
    unsigned char x2 = 156;

    printf("%d\n", rightrot(x1, 3));
    printf("%d\n", rightrot(x2, 6));
}

unsigned char rightrot(unsigned char x, unsigned n)
{
    return (x>>n) | ((x & ~(~0<<n))<<(sizeof(x)*8-n));
}
