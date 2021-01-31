/*
 * Exercise 1-13
 *
 * Write a program to print a histogram of the lengths of words in its input.
 */

#include <stdio.h>

#define MAX_SIZE    15 /* max size of words */
#define IN           1 /* inside word */
#define OUT          0 /* outside word */

int main()
{
    int c, i, j, state, count;
    int sizes[MAX_SIZE + 1];    /* intend to burn 0 index to avoid confusion */

    /* initialize array entries to 0 */
    for (i = 0; i <= MAX_SIZE; ++i)
        sizes[i] = 0;

    /* process input */
    count = 0;
    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {      /* end of current word */
                state = OUT;
                if (count > MAX_SIZE)
                    ++sizes[MAX_SIZE];
                else
                    ++sizes[count];
                count = 0;
            }
        }
        else {
            if (state == OUT)
                state = IN;
            ++count;
        }
    }

    /* print histogram */
    printf("Histogram of Word Lengths:\n");
    for (i = 1; i <= MAX_SIZE; ++i) {
        printf("%d: ", i);
        for (j = 0; j < sizes[i]; ++j)
            putchar('*');
        putchar('\n');
    }
}
