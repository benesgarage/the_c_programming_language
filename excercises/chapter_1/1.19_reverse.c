#include <stdio.h>

#define MINLINE 80
#define MAXLINE 1000

int getlinee(char line[], int maxline);
void reverse(char to[], char from[], int len);

int main()
{
    int len;
    char line[MAXLINE];

    while((len = getlinee(line, MAXLINE)) > 0) {
        char nline[MAXLINE] = {};
        reverse(nline, line, len);
        printf("Reversed: %s\n", nline);
    }

    return 0;
}

void reverse(char to[], char from[], int length)
{
    for(int i=0;i<length-1;++i) {
        to[length - 2 - i] = from[i];
    }

    to[length - 1] = from[length - 1];
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

