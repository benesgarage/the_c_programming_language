#include <stdio.h>

#define MAXLINE 100
#define BLANKS_PER_TAB 4

int getlinee(char line[], int maxline);
void detab(char line[], char nline[], int len);

int main()
{
    int len;
    char line[MAXLINE];

    while((len = getlinee(line, MAXLINE)) > 0) {
        // If line is full of tabs, it could be four times larger
        char nline[MAXLINE * BLANKS_PER_TAB] = {};
        detab(line, nline, len);

        printf("Detabbed: %s\n", nline);
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

void detab(char line[], char nline[], int length)
{
    int j=0;

    for(int i=0; i<length - 1; ++i) {
        if('\t' == line[i]) {
            int k = j+BLANKS_PER_TAB;
            for(j; j<k; ++j) {
                nline[j] = ' ';
            }
        } else {
            nline[j] = line[i];
            ++j;
        }
    }
}
