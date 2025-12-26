#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;

    if (scanf("%d", &N) != 1 || N <= 0) {
        return 1;
    }

    int *scores = (int *)malloc(N * sizeof(int));
    if (scores == NULL) {
        return 1;
    }

    for (int i = 0; i < N; i++) {
        if (scanf("%d", scores + i) != 1) {
            free(scores);
            return 1;
        }
    }

    for (int *p = scores + N - 1; p >= scores; p--) {
        printf("%d\n", *p);
    }

    free(scores);
    return 0;
    // End of main
}
