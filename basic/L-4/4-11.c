#include <stdio.h>

#define ROWS 2
#define COLS 4

int main() {
    int mat[ROWS][COLS];
    int sum = 0;
    int r, c;

    // Input values
    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++) {
            scanf("%d", &mat[r][c]);
        }
    }

    // Display matrix and calculate sum
    printf("\n--- MATRIX CONTENT ---\n");
    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++) {
            printf("%4d", mat[r][c]);
            sum += mat[r][c];
        }
        printf("\n");
    }

    printf("\nSum of all elements: %d\n", sum);

    return 0;
}
