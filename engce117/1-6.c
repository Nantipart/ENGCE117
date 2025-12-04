#include <stdio.h>
#include <stdlib.h> // For malloc and free

// Declare the prototype of the GetMatrix function
int* GetMatrix(int *row, int *col);

int main() {
    int *data, m, n;

    // Get the matrix from user input and print it
    data = GetMatrix(&m, &n);

    // Free allocated memory
    free(data);

    return 0;
}

int* GetMatrix(int *row, int *col) {
    // Ask the user for the number of rows and columns
    printf("Enter number of rows: ");
    scanf("%d", row);
    printf("Enter number of columns: ");
    scanf("%d", col);

    // Dynamically allocate memory for the matrix
    int *matrix = (int *)malloc((*row) * (*col) * sizeof(int));

    // Ask the user to input the values for the matrix
    printf("Enter the values for the matrix:\n");
    for (int i = 0; i < (*row); i++) {
        for (int j = 0; j < (*col); j++) {
            printf("Matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i * (*col) + j]);
        }
    }

    // Print the matrix
    printf("The matrix you entered is:\n");
    for (int i = 0; i < (*row); i++) {
        for (int j = 0; j < (*col); j++) {
            printf("%d ", matrix[i * (*col) + j]);
        }
        printf("\n");
    }

    return matrix;
}