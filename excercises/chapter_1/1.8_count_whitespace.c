#include <stdio.h>

int main()
{
    double nl = 0;
    double bl = 0;
    double tab = 0;
    int c;

    while((c = getchar()) != EOF) {
        switch(c) {
            case '\n':
                ++nl;
                break;
            case ' ':
                ++bl;
                break;
            case '\t':
                ++tab;
        }
    }

    printf("Newline: %.0f Blank: %.0f Tab: %.0f", nl, bl, tab);

    return 0;
}
