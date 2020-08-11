#include <stdio.h>

#define MAXLINE 100

int getlinee(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while((len = getlinee(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            printf("Test: %s\n", line);
            copy(longest, line);
        }
    }
    if (max > 0) {
        printf("Line count: (including null terminator) %d\n", max);
        printf("Line: %s\n", longest);
    }
    return 0;
}

int getlinee(char line[], int maxline)
{
    int c, i;

    for (i=0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < maxline - 1) {
            line[i] = c;
        } else if (i == maxline -1) {
            line[i] = '\0';
        }
    }

    if (c == '\n' && i < maxline - 1) {
        line[i] = '\n';
        ++i;
    }

    if (i == maxline - 1) {
        line[i] = '\0';
        ++i;
    }

    return i;
}

void copy(char to[], char from[])
{
    int i;

    for (i=0; i <= MAXLINE; ++i) {
        to[i] = from[i];
    }
}
