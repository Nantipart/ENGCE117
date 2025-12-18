#include <stdio.h>

#define SIZE 3

int main() {
    int matrix[SIZE][SIZE];
    int r, c;

    // Input values into 2D array
    for (r = 0; r < SIZE; r++) {
        for (c = 0; c < SIZE; c++) {
            scanf("%d", &matrix[r][c]);
        }
    }

    // Display result
    printf("\n--- MATRIX DISPLAY ---\n");
    for (r = 0; r < SIZE; r++) {
        for (c = 0; c < SIZE; c++) {
            printf("%4d", matrix[r][c]);
        }
        printf("\n");
    }

    return 0;
}
