#include <stdio.h>

void GetMatrix(int arr[], int *r, int *c);

int main() {
    int m, n;
    int data[100];
    GetMatrix(data, &m, &n);

    return 0;
}

void GetMatrix(int arr[], int *r, int *c) {
    printf("Rows: ");
    scanf("%d", r);
    printf("Cols: ");
    scanf("%d", c);

    for (int i = 0; i < *r * *c; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < *r; i++) {
        for (int j = 0; j < *c; j++) {
            printf("%d ", arr[i * *c + j]);
        }
        printf("\n");
    }
}