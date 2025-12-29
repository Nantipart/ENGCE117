#include <stdio.h>

int main() {
    int N;
    
    if (scanf("%d", &N) != 1) {
        return 1;
    }

    int arr[N];
    int *ptr = arr;

    /* Get data into an array */
    for (int k = 0; k < N; k++) {
        if (scanf("%d", ptr + k) != 1) {
            return 1;
        }
    }

    /* Show results back */
    for (int k = N - 1; k >= 0; k--) {
        printf("%d\n", *(arr + k));
    }

    return 0;
}
