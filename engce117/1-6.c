#include <stdio.h>
#include <stdlib.h>

// Function Prototype
int *GetMatrix(int *row, int *col);

int main() {
    int *data, m, n;

    // Call the function
    data = GetMatrix(&m, &n);

    printf("\n--- Result ---\n");
    printf("Matrix Size: %d x %d", m, n);
    printf("\nData: ");
    for(int i = 0; i < m * n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
// ----------------------------------------------------

int *GetMatrix(int *ptrRow, int *ptrCol) {
    int *myMatrix; // Pointer to hold the matrix data

    // 1. Get matrix dimensions
    // Prompt user for input
    printf("Enter dimensions (Rows): ");
    scanf("%d", ptrRow, ptrCol);
    printf("Enter dimensions (Cols): ");
    scanf("%d", ptrCol);


    // 2. Allocate memory dynamically
    // Calculate total size: rows * columns * size of int
    int totalSize = (*ptrRow) * (*ptrCol);
    myMatrix = (int *)malloc(totalSize * sizeof(int));

    // Verify memory allocation (Fix for CLO4: Stability issue)
    if (myMatrix == NULL) {
        return NULL; // Return NULL if allocation fails
    }

    // 3. Input matrix elements
    printf("Input data elements:\n");
    for (int k = 0; k < totalSize; k++) {
        // Read input directly into the allocated array
        scanf("%d", &myMatrix[k]);
    }

    // 4. Return the pointer to the allocated memory
    return myMatrix;
}