#include <stdio.h>

#define SIZE 3

int main(void) {
    int data[SIZE];
    int *ptr;
    int i;

    printf("Input %d integers\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        printf("Index %d -> ", i);
        scanf("%d", &data[i]);
    }

    ptr = data;   // Pointer points to first element

    printf("\n--- ARRAY & POINTER INSPECTION ---\n");
    printf("Idx | Direct | Pointer | Address\n");
    printf("---------------------------------\n");

    for (i = 0; i < SIZE; i++) {
        printf("%3d | %6d | %7d | %p\n",
               i,
               data[i],
               *ptr,
               (void *)ptr);
        ptr++;   // Move pointer to next element
    }

    return 0;
}
