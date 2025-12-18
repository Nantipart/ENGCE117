#include <stdio.h>

#define A_ROWS 2
#define A_COLS 3
#define B_ROWS 2
#define B_COLS 3

void showMatrix(int r, int c, int m[r][c]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%4d ", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[A_ROWS][A_COLS];
    int B[B_ROWS][B_COLS];
    int C[A_ROWS][B_ROWS];   // Result = 2x2
    int i, j, k;

    // Input Matrix A
    for (i = 0; i < A_ROWS; i++) {
        for (j = 0; j < A_COLS; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input Matrix B
    for (i = 0; i < B_ROWS; i++) {
        for (j = 0; j < B_COLS; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Multiply A (2x3) with B^T (3x2) without creating BT
    for (i = 0; i < A_ROWS; i++) {
        for (j = 0; j < B_ROWS; j++) {
            C[i][j] = 0;
            for (k = 0; k < A_COLS; k++) {
                C[i][j] += A[i][k] * B[j][k];
            }
        }
    }

    printf("\nMatrix A:\n");
    showMatrix(A_ROWS, A_COLS, A);

    printf("\nMatrix B:\n");
    showMatrix(B_ROWS, B_COLS, B);

    printf("\nResult Matrix C (A x B^T):\n");
    showMatrix(A_ROWS, B_ROWS, C);

    return 0;
}
