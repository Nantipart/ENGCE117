#include <stdio.h>

int main() {
    int number;
    int valid = 0;   // input status

    while (!valid) {
        printf("Enter a number (1-10): ");

        if (scanf("%d", &number) == 1 && number >= 1 && number <= 10) {
            valid = 1;               // correct input
        } else {
            printf("Error: Value must be 1-10.\n");
            while (getchar() != '\n'); // clear buffer
        }
    }

    printf("Input accepted: %d\n", number);
    return 0;
}
