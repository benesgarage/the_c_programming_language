#include <stdio.h>

int main()
{
    int state;
    while (state = (getchar() != EOF))
    {
        printf("State at %d, continue running...\n", state);
    }

    printf("State at %d, done!\n", state);

    return 0;
}
