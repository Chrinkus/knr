/*
 * Exercise 2-9
 *
 * In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
 * in x. Explain why. Use this observation to write a faster version of
 * bitcount.
 *
 * Explanation: As we AND x with itself less 1 we trade the rightmost bit for
 * lesser bits that the initial x does not have. By ANDing we discard those as
 * well leaving only the higher order bits of x.
 */

#include <stdio.h>

int bitcount(unsigned x);

int main()
{
    unsigned x1 = 37;       /* has 3 - 1 bits */
    unsigned x2 = 64;       /* has 1 - 1 bit */
    unsigned x3 = 255;      /* has 8 - 1 bits */

    printf("%d\n", bitcount(x1));
    printf("%d\n", bitcount(x2));
    printf("%d\n", bitcount(x3));
}

int bitcount(unsigned x)
    /* faster because we only iterate through the 1 bits */
{
    int b;

    for (b = 0; x != 0; x &= (x-1))
        ++b;

    return b;
}
