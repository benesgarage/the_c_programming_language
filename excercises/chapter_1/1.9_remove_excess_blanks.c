#include <stdio.h>

int main()
{
    int c;
    int lc;

    while((c = getchar()) != EOF) {
        if (lc != ' ' || c != lc) {
            putchar(c);
        }
        lc = c;
    }

    return 0;
}
