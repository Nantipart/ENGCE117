#include <stdio.h>

void showStatus(int stock, float penalty) {
    printf("Stock: %d, Total Penalties: %.2f\n", stock, penalty);
}

int main() {
    int initStock, N, cmd, qty;
    int stock;
    float penaltyFee, totalPenalty = 0.0;

    if (scanf("%d %f %d", &initStock, &penaltyFee, &N) != 3)
        return 1;

    stock = initStock;

    while (N--) {
        if (scanf("%d %d", &cmd, &qty) != 2)
            break;

        if (cmd == 1) {                      // restock
            stock += qty;
            printf("Received %d units.\n", qty);
        }
        else if (cmd == 2) {                 // ship
            if (qty <= 0) {
                printf("Error: Quantity must be positive.\n");
            }
            else if (qty > stock) {
                totalPenalty += penaltyFee;
                printf("FAILURE: Insufficient stock. PENALTY %.2f added.\n", penaltyFee);
            }
            else {
                stock -= qty;
                printf("Shipped %d units.\n", qty);
            }
        }
        else if (cmd == 3) {                 // status
            showStatus(stock, totalPenalty);
        }
        else {
            printf("Error: Invalid Command.\n");
        }
    }

    return 0;
}
