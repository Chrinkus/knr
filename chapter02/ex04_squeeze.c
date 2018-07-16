/*
 * Exercise 2-4
 *
 * Write an alternate version of squeeze(s1,s2) that deletes each character in
 * s1 that matches any character in s2.
 */

#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main()
{
    char s1[] = "tuesday";
    char s2[] = "sad";
    char s3[] = "valentine";
    char s4[] = "live";

    squeeze(s1, s2);
    printf("%s\n", s1);

    squeeze(s3, s4);
    printf("%s\n", s3);
}

void squeeze(char s1[], char s2[])
{
    int i, j, k;

    for (i = k = 0; s1[i] != '\0'; ++i) {
        char match = 0;
        for (j = 0; s2[j] != '\0'; ++j)
            if (s1[i] == s2[j])
                match = 1;

        if (!match)
            s1[k++] = s1[i];
    }
    s1[k] = '\0';
}
