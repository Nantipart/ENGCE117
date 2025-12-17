#include <stdio.h>

int main() {
    int choice;
    float total = 0.0;
    float money;

    // price table (index = choice)
    float price[] = {0.0, 15.0, 10.0, 25.0};

    while (1) {
        printf("\n--- Vending Machine ---\n");
        printf("1. Coke (15.00)\n");
        printf("2. Water (10.00)\n");
        printf("3. Snack (25.00)\n");
        printf("4. Exit and Pay\n");
        printf("Current Total: %.2f\n", total);

        if (scanf("%d", &choice) != 1)
            return 1;

        if (choice == 4)
            break;

        if (choice >= 1 && choice <= 3) {
            total += price[choice];
            printf("Item added.\n");
        } else {
            printf("Invalid selection.\n");
        }
    }

    if (total <= 0.0) {
        printf("No items purchased. Goodbye!\n");
        return 0;
    }

    printf("\nTotal due: %.2f\n", total);
    printf("Enter paid amount: ");

    if (scanf("%f", &money) != 1)
        return 1;

    if (money >= total)
        printf("Change: %.2f\n", money - total);
    else
        printf("Not enough money.\n");

    return 0;
}
