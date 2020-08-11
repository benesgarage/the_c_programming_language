#include <stdio.h>

#define MINLINE 80
#define MAXLINE 1000

int getlinee(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;
    char line[MAXLINE];

    while((len = getlinee(line, MAXLINE)) > 0) {
        if (len > MINLINE) {
            printf("Over %d chars: %s\n", MINLINE, line);
        }
    }

    return 0;
}

int getlinee(char line[], int maxline)
{
    int c, i;

    for (i=0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < maxline - 1) {
            line[i] = c;
        } else if (i == maxline - 1) {
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

