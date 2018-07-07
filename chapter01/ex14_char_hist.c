/*
 * Exercise 1-14
 *
 * Write a program to print a histogram of the frequencies of different
 * characters in its input.
 *
 * I will be limiting my frequency tracking to lowercase letters. To make up
 * for this limitation I will produce a vertical histogram.
 */

#include <stdio.h>

#define LOW_CHAR    'a'
#define HIGH_CHAR   'z'

int main()
{
    int c, i, j, count, range, max_count;
    range = HIGH_CHAR - LOW_CHAR + 1;   /* +1 for inclusive range [LOW:HIGH] */

    int freqs[range];
    for (i = 0; i < range; ++i)
        freqs[i] = 0;

    while ((c = getchar()) != EOF) {
        if (LOW_CHAR <= c && c <= HIGH_CHAR)
            ++freqs[c - LOW_CHAR];
    }

    max_count = 0;
    for (i = 0; i < range; ++i)
        if (freqs[i] > max_count)
            max_count = freqs[i];

    printf("Histogram of Character Frequencies:\n");
    for (i = max_count; i > 0; --i) {
        for (j = 0; j < range; ++j)
            if (freqs[j] >= i)
                putchar('*');
            else
                putchar(' ');
        putchar('\n');
    }

    for (i = 0; i < range; ++i)
        putchar(LOW_CHAR + i);
    putchar('\n');
}

