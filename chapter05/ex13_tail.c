/*
 * Exercise 13
 *
 * Write the program tail, which prints the last n lines of it's input. By
 * default, n is 10, let us say, but it can be changed by an optional argument,
 * so that
 *      $ ./tail -n
 * prints the last n lines. The program should behave rationally no matter how
 * unreasonable the input or the value of n. Write the program so it makes the
 * best use of available storage; lines should be stored as in the sorting
 * program from Section 5.6, not in a two-dimensional array of fixed size.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES    5000            /* max lines to be sorted */

char *lineptr[MAXLINES];            /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

int main(int argc, char *argv[])
{
    int nlines, nprint = 10;

    if (--argc > 0 && (*++argv)[0] == '-') {
        nprint = atoi(++argv[0]);
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        if (nlines <= nprint)
            writelines(lineptr, nlines);
        else
            writelines(lineptr + nlines - nprint, nprint);
        return 0;
    } else {
        printf("error: input too big to read\n");
        return 1;
    }
}

#define MAXLEN  1000                /* max length of any input line */
int my_getline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = my_getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0';     /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; ++i)
        printf("%s\n", lineptr[i]);
}

/* my_getline: get a line from input */
int my_getline(char *s, int lim)
{
    char *p = s;
    int c;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - p;
}

#define ALLOCSIZE   10000           /* size of available space */

static char allocbuf[ALLOCSIZE];    /* storage for alloc */
static char *allocp = allocbuf;     /* next free position */

/* alloc: return pointer to n characters */
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else
        return 0;
}
