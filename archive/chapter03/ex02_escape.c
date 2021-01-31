/*
 * Exercise 3-2
 *
 * Write a function escape(s,t) that converts characters like newline and tab
 * into visible escape sequences like \n and \t as it copies the string t to s.
 * Use a switch. Write a function for the other direction as well, converting
 * escape sequences into the real characters.
 */

#include <stdio.h>

#define MAX_CHAR 1000       /* maximum characters per line */

int my_getline(char s[], int lim);
void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main()
{
    int len;
    char buf[MAX_CHAR];
    char out1[MAX_CHAR];
    char out2[MAX_CHAR];

    while ((len = my_getline(buf, MAX_CHAR)) > 0) {
        escape(out1, buf);
        printf("%s\n", out1);
        
        unescape(out2, out1);
        printf("%s\n", out2);
    }
}

int my_getline(char s[], int lim)
{
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}

void escape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; ++i) {

        switch (t[i]) {
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }

    s[j] = '\0';
}

void unescape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; ++i) {

        if (t[i] == '\\') {         /* possible escape char */

            switch (t[i+1]) {
                case 'n':
                    s[j++] = '\n';
                    ++i;
                    break;
                case 't':
                    s[j++] = '\t';
                    ++i;
                    break;
                default:
                    s[j++] = '\\';  /* just a forward slash */
            }
        }
        else {
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}
