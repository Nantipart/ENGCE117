#include <stdio.h>

/* function prototypes */
void calculate(int a, int b, int *sum, int *product);
void showResult(int a, int b, int sum, int product);

int main(void) {
    int numA, numB;
    int resultSum, resultMul;

    printf("Enter two integers (A B): ");
    scanf("%d %d", &numA, &numB);

    calculate(numA, numB, &resultSum, &resultMul);

    showResult(numA, numB, resultSum, resultMul);

    return 0;
}

/* calculate sum and product using pointers */
void calculate(int a, int b, int *sum, int *product) {
    *sum = a + b;
    *product = a * b;
}

/* display calculation result */
void showResult(int a, int b, int sum, int product) {
    printf("\n--- CALCULATION REPORT ---\n");
    printf("Input A : %d\n", a);
    printf("Input B : %d\n", b);
    printf("Sum     : %d\n", sum);
    printf("Product : %d\n", product);
}
