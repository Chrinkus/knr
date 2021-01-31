/*
 * Exercise 3-3
 *
 * Write a function expand(s1,s2) that expands shorthand notation like a-z in
 * the string s1 into the equivalent complete list abc...xyz in s2. Allow for
 * letters of either case and digits. Arrange that a leading or trailing - is
 * taken literally.
 */

#include <stdio.h>
#include <ctype.h>

#define MAX_CHAR    1000        /* maximum characters in a buffer */

void expand(char s1[], char s2[]);

int main()
{
    int len;
    char buf[MAX_CHAR];

    char r1[] = "-a-zChristmasA-ZTuesday0-9-";

    expand(r1, buf);
    printf("%s\n", buf);
}

void expand(char s1[], char s2[])
{
    int c, i, j;

    for (i = j = 0; s1[i] != '\0'; ++i) {

        if (s1[i] == '-'
                && i > 0                /* bounds check */
                && s1[i-1] < s1[i+1]    /* range is ascending */
                && isalnum(s1[i-1])
                && isalnum(s1[i+1]))
            for (c = ++s1[i-1]; c != s1[i+1]; ++c)
                s2[j++] = c;
        else
            s2[j++] = s1[i];
    }
    s2[j] = '\0';
}
