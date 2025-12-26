#include <stdio.h>

// Function prototype
void add_ten(int *value);

int main(void) {
    int num;

    printf("Input number: ");
    if (scanf("%d", &num) != 1) {
        return 1;
    }

    printf("\n--- POINTER RESULT ---\n");
    printf("Before call : %d\n", num);

    add_ten(&num);

    printf("After call  : %d\n", num);

    return 0;
}

// Function definition
void add_ten(int *value) {
    (*value) += 10;
}
