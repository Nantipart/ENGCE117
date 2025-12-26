#include <stdio.h>

// Function prototype
void exchange(int *a, int *b);

int main(void) {
    int x, y;

    printf("Input first number : ");
    scanf("%d", &x);

    printf("Input second number: ");
    scanf("%d", &y);

    printf("\n--- SWAPPING RESULT ---\n");
    printf("Before -> x = %d , y = %d\n", x, y);

    exchange(&x, &y);

    printf("After  -> x = %d , y = %d\n", x, y);

    return 0;
}

// Function definition
void exchange(int *a, int *b) {
    int temp;

    temp = *a;
    *a   = *b;
    *b   = temp;
}
