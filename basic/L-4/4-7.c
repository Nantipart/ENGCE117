#include <stdio.h>

#define MAX_SIZE 10

int main() {
    int values[MAX_SIZE];
    int size;
    int key;
    int freq = 0;
    int idx;

    // Read number of elements
    scanf("%d", &size);

    if (size < 1 || size > MAX_SIZE) {
        size = MAX_SIZE;
    }

    // Read array elements
    for (idx = 0; idx < size; idx++) {
        scanf("%d", &values[idx]);
    }

    // Read search key
    scanf("%d", &key);

    // Count frequency
    for (idx = 0; idx < size; idx++) {
        if (values[idx] == key) {
            freq++;
        }
    }

    // Display summary
    printf("=== FREQUENCY SUMMARY ===\n");
    printf("N = %d\n", size);

    printf("Data: ");
    for (idx = 0; idx < size; idx++) {
        printf("%d ", values[idx]);
    }
    printf("\n");

    printf("Key = %d\n", key);
    printf("Occurrences = %d\n", freq);

    return 0;
}
