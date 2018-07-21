/*
 * Exercise 3-1
 *
 * The text's binary search makes two tests inside the loop, when one would
 * suffice. Write a version with only one test inside the loop and measure the
 * difference in run-time.
 *
 * No idea how to measure this at runtime without a significant data set.
 * Running the program under the 'time' command does not produce measurably
 * different results.
 */

#include <stdio.h>

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main()
{
    int res, vals[] = { 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 };

    res = binsearch(4, vals, 11);
    printf("%d = -1\n", res);

    res = binsearch(144, vals, 11);
    printf("%d = 10\n", res);

    res = binsearch(1, vals, 11);
    printf("%d = 0\n", res);

    res = binsearch(21, vals, 11);
    printf("%d = 6\n", res);

    res = binsearch(0, vals, 11);
    printf("%d = -1\n", res);
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int binsearch2(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    do {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    } while (low <= high && v[mid] != x);

    return v[mid] == x ? mid : -1;
}
