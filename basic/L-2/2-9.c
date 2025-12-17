#include <stdio.h>

int main() {
    // Variable declarations
    int initialStock, N, cmdCode, quantity, i;
    float PENALTY_FEE;
    int currentStock;
    float totalPenalties = 0.0;

    // Receive initial setup values
    if (scanf("%d %f %d", &initialStock, &PENALTY_FEE, &N) != 3) {
        return 1;
    }
    
    // Set current stock to initial value
    currentStock = initialStock;

    // Loop through N transactions
    for (i = 0; i < N; i++) {

        // Read command code and quantity for this transaction
        if (scanf("%d %d", &cmdCode, &quantity) != 2) {
            break;
        }

        // Process command based on cmdCode
        switch (cmdCode) {
            case 1: // Command 1: Restock (Receive goods)
                currentStock += quantity;
                printf("Received %d units.\n", quantity);
                break;

            case 2: // Command 2: Ship goods (Dispatch)
                if (quantity <= 0) {
                    // Check for invalid quantity
                    printf("Error: Quantity must be positive.\n");
                } else if (quantity <= currentStock) {
                    // Enough stock available, proceed to ship
                    currentStock -= quantity;
                    printf("Shipped %d units.\n", quantity);
                } else {
                    // Not enough stock, apply penalty
                    totalPenalties += PENALTY_FEE;
                    printf("FAILURE: Insufficient stock. PENALTY %.2f added.\n", PENALTY_FEE);
                }
                break;

            case 3: // Command 3: Check Status
                // Display current stock and accumulated penalties
                printf("Stock: %d, Total Penalties: %.2f\n", currentStock, totalPenalties);
                break;

            default:
                // Handle invalid command codes
                printf("Error: Invalid Command.\n");
                break;
        }
    }

    return 0;
}