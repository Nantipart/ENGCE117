#include <stdio.h>
#include <stdlib.h>

#define SHIPPING_FEE 50.0

// Order structure
struct Order {
    int id;
    float price;
    int qty;
};

// calculate total price of one order
float calcOrderTotal(struct Order o) {
    float total = o.price * o.qty + SHIPPING_FEE;
    return (total >= 500.0) ? total * 0.90 : total;
}

int main() {
    int N;
    float grandTotal = 0.0;

    if (scanf("%d", &N) != 1 || N <= 0)
        return 1;

    // dynamic allocation instead of VLA
    struct Order *orders = malloc(N * sizeof(struct Order));
    if (!orders)
        return 1;

    for (int i = 0; i < N; i++) {
        if (scanf("%d %f %d",
                  &orders[i].id,
                  &orders[i].price,
                  &orders[i].qty) != 3) {
            free(orders);
            return 1;
        }

        // accumulate grand total
        grandTotal += calcOrderTotal(orders[i]);
    }

    printf("Grand Total: %.2f\n", grandTotal);

    free(orders);
    return 0;
}
