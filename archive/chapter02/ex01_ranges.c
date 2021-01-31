/*
 * Exercise 2-1
 *
 * Write a program to determine the ranges of char, short, int and long
 * variables, both signed and unsigned, by printing the appropriate values from
 * the standard headers and by direct computation.
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int main()
{
    printf("Ranges of Signed Integral Types:\n");
    printf("char from %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("short from %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("int from %d to %d\n", INT_MIN, INT_MAX);
    printf("long from %ld to %ld\n", LONG_MIN, LONG_MAX);

    putchar('\n');

    printf("Ranges of Unsigned Integral Types:\n");
    printf("u_char from %d to %d\n", 0, UCHAR_MAX);
    printf("u_short from %d to %d\n", 0, USHRT_MAX);
    printf("u_int from %d to %u\n", 0, UINT_MAX);
    printf("u_long from %d to %lu\n", 0, ULONG_MAX);

    putchar('\n');

    printf("Ranges of Floating Types:\n");
    printf("float from %f to %f\n", FLT_MIN, FLT_MAX);
    printf("double from %f to %f\n", DBL_MIN, DBL_MAX);

    putchar('\n');

    printf("Floating Point Calculation:\n");
    printf("Radix %d, Max exponent %d, Mantissa %d\n",
            FLT_RADIX, FLT_MAX_EXP, FLT_MANT_DIG);

    double calc_max = pow(FLT_RADIX, FLT_MAX_EXP);
    double macro_max = FLT_MAX;
    printf("Float max: %f\n", calc_max);
    printf("Difference: %f\n", macro_max - calc_max);
}
