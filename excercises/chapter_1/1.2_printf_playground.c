#include <stdio.h>
int main() {
    char n = 'J';
    printf("Char conversion/representation:\n");
    printf("%15s %3c\n", "Using char", n);
    printf("%15s %3d\n", "To intger", n);
    printf("%15s %3x\n", "To hexadecimal", n);
    printf("%15s %3X\n", "To upper hex", n);
    printf("%15s %3o\n", "To octal", n);
    printf("\n\n");
    printf("Always escape your backslashes \\r\\n \n\n");
    return 0;
}
