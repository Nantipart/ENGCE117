#include <stdio.h>

int main() {
    int N, i;

    // 1. Receive number of elements (N)
    if (scanf("%d", &N) != 1) {
        return 1; // Exit if input is invalid
    }

    int scores[N];

    for (i = 0; i < N; i++) {
        if (scanf("%d", &scores[i]) != 1) {
            return 1;
        }
    }

    for (i = N - 1; i >= 0; i--) {
        printf("%d\n", scores[i]);
    }

    return 0;
}