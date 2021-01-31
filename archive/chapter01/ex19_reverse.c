/*
 * Exercise 1-19
 *
 * Write a function reverse(s) that reverses the character string s. Use it to
 * write a program that reverses its input a line at a time.
 */

#include <stdio.h>

#define MAX_LEN 280         /* Maximum length of string to handle */

int my_getline(char s[], int max);
void reverse(char s[], int len);
void swap(char s[], int i, int j);
int trim(char s[], int len);

int main()
{
    int len;
    char line[MAX_LEN];

    while ((len = my_getline(line, MAX_LEN)) > 0) {
        len = trim(line, len);
        reverse(line, len);
        printf("%s\n", line);
    }
}

int my_getline(char s[], int max)
{
    int c, i;

    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

void reverse(char s[], int len)
{
    int i = 0;
    char temp;

    --len;              /* don't move the null character */
    while (i < len) {
        swap(s, i, len);
        ++i;
        --len;
    }
}

void swap(char s[], int i, int j)
{
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

int trim(char s[], int len)
{
    char c;
    --len;                  /* skip null char */

    for (c = s[len]; len >= 0 && (c == '\n' || c == '\t' || c == ' ');
            c = s[--len]) {
        s[len] = '\0';
    }

    return len + 1;         /* give back null char */
}
