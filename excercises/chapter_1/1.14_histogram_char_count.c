#include <stdio.h>

void main ()
{
    char cc[255] = {};
    char c;
    
    while((c = getchar()) != EOF) {
        ++cc[c];
    }

    printf("\n");
    for (int i=0;i<256;i++) {
        if(0 != cc[i]) {
            printf("Count for the character %c: %i\n", i, cc[i]);
        }
    }
}
