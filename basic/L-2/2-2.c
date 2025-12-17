#include <stdio.h>

int main() {
    int N, i, quantity;
    float unitPrice, itemCost, grandTotal = 0.0;

    if (scanf("%d", &N) != 1) {
        return 1; // Exit if input is invalid
    }

    // Loop N times to process each item
    for (i = 0; i < N; i++) {

        scanf("%f %d", &unitPrice, &quantity);

        itemCost = unitPrice * quantity;

        if (unitPrice >= 1000.00) {
            // Deduct 10% from the item cost
            itemCost = itemCost * 0.90; 
        } 

        // Add the calculated cost to the grand total
        grandTotal += itemCost;
    }

    // Print the final result formatted to 2 decimal places
    printf("Grand Total: %.2f\n", grandTotal);
    
    return 0;
}