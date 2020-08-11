#include <stdio.h>

#define MAXWORD 10
#define MAXHIST 25

int main()
{
    char c;
    int cw = 0;
    int wl[MAXWORD] = {};
    int maxl = 0;
    int wovfl = 0;
    int hovfl = 0;
    int len;

    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (wl[cw] > maxl) maxl = wl[cw];
            if (wl[cw] > 0) ++cw;
        } else {
            ++wl[cw];
        }
        /* Skip and fast-forward to next word if current reached char limit */
        if (wl[cw] >= MAXHIST) {
            hovfl = 1;
            wl[cw] = 0;
            while (c != ' ' && c != '\t' && c != '\n') c = getchar();
        }
        /* Stop reading if we've reached the word limit */
        if (cw >= MAXWORD) {
            wovfl = 1;
            break;
        }
    }

    for (int i = 0; i < MAXWORD; i++) {
        if (wl[i] > 0) {
            printf("%2d - %2d\t", i, wl[i]);
            
            /* Normalize length of histogram */
            len = wl[i] * MAXHIST / maxl;

            while (len >= 0) {
                printf("*");
                --len;
            }

            printf("\n");
        }
    }

    if (wovfl) {
        printf("Stopped reading input after %d words.\n", MAXWORD);
    }

    if (hovfl) {
        printf("Ignored words exceeding %d characters.\n", MAXHIST);
    }

    return 0;
}
