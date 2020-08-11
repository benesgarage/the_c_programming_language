#include <stdio.h>

int main()
{
    int c;

    while((c = getchar()) != EOF) {
        switch(c) {
            case '\t':
                putchar('\\');
                putchar('t');
                break;
            case '\\':
                putchar('\\');
                putchar('\\');
                break;
            case '\b':
                putchar('\\');
                putchar('b');
                break;
            default:
                putchar(c);
        }
    }

    return 0;
}
