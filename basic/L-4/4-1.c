#include <stdio.h>

int main() {
    int N, i;

    // Read number of elements
    if (scanf("%d", &N) != 1) {
        return 1;
    }

    // Declare array of size N
    int scores[N];

    // Input N integers into array
    for (i = 0; i < N; i++) {
        if (scanf("%d", &scores[i]) != 1) {
            return 1;
        }
    }

    // Print values in reverse order
    for (i = N - 1; i >= 0; i--) {
        printf("%d\n", scores[i]);
    }

    return 0;
}
