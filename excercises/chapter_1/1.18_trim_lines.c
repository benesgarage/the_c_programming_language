#include <stdio.h>

#define MINLINE 80
#define MAXLINE 1000

int getlinee(char line[], int maxline);
void copy(char to[], char from[], int len);

int main()
{
    int len;
    char line[MAXLINE];

    int i;
    while((len = getlinee(line, MAXLINE)) > 0) {
        int nlen = len;
        char nline[MAXLINE] = {};

        for (i=len - 2; i >= 0; --i) {
            if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n') {
                nlen -= 1;
            } else {
                break;
            }
        }

        copy(nline, line, nlen);
        printf("Trimmed: %s\n", nline);
    }

    return 0;
}

void copy(char to[], char from[], int len)
{
    int i;

    for (i=0; i < len - 1; ++i) {
        to[i] = from[i];
    }

    to[i+1] == '\0';

}


int getlinee(char line[], int maxline)
{
    int prev, c, i;

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

