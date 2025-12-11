#include <stdio.h>
#include <stdlib.h>

// return dynamic matrix, row/col via pointer
int *GetMatrix(int *row, int *col);

int main() {
    int *data, m, n;

    data = GetMatrix(&m, &n);
    if (!data) {          // check allocation
        printf("Error: allocation failed.\n");
        return 1;
    }

    printf("\n--- Result ---\n");
    printf("Matrix Size: %d x %d\n", m, n);

    for (int i = 0; i < m * n; i++)
        printf("%d ", data[i]);

    free(data);           // free memory
    return 0;
}

// ---------------------------

int *GetMatrix(int *r, int *c) {
    printf("Enter Rows: ");
    scanf("%d", r);

    printf("Enter Cols: ");
    scanf("%d", c);

    if (*r <= 0 || *c <= 0) return NULL;   // invalid size

    int size = (*r) * (*c);
    int *mat = malloc(size * sizeof(int));
    if (!mat) return NULL;                 // malloc failed

    printf("Input elements:\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &mat[i]);             // fill data

    return mat;                            // return pointer
}