#include <stdio.h>

#define SIZE 5

int main() {
    int data[SIZE];
    int even = 0, odd = 0;
    int idx;

    // Input numbers
    for (idx = 0; idx < SIZE; idx++) {
        scanf("%d", &data[idx]);
    }

    // Analyze numbers
    for (idx = 0; idx < SIZE; idx++) {
        if (data[idx] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }

    // Display result
    printf("=== NUMBER REPORT ===\n");
    printf("Numbers: ");
    for (idx = 0; idx < SIZE; idx++) {
        printf("%d ", data[idx]);
    }
    printf("\n");

    printf("Even count: %d\n", even);
    printf("Odd count: %d\n", odd);

    return 0;
}
