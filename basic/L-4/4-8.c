#include <stdio.h>

#define MAX_SIZE 10

int main() {
    int data[MAX_SIZE];
    int N, i, j;
    int count;

    scanf("%d", &N);

    if (N < 1 || N > MAX_SIZE) {
        N = MAX_SIZE;
    }

    for (i = 0; i < N; i++) {
        scanf("%d", &data[i]);
    }

    // Sort array (Ascending Order)
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            if (data[i] > data[j]) {
                int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }

    printf("\n--- FREQUENCY ANALYSIS REPORT ---\n");
    printf("Total elements recorded (N): %d\n", N);

    printf("\n--- FREQUENCY TABLE ---\n");
    printf("Number | Frequency\n");
    printf("-------|----------\n");

    for (i = 0; i < N; i++) {
        count = 1;

        while (i < N - 1 && data[i] == data[i + 1]) {
            count++;
            i++;
        }

        printf("   %d   |    %d\n", data[i], count);
    }

    return 0;
}
