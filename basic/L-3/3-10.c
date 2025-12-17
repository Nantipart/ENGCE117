#include <stdio.h>

#define VAT_RATE 0.07

struct Item {
    char name[50];
    float price;
    int qty;
};

// Function to calculate item total
float calcItemTotal(float price, int qty) {
    return price * qty;
}

int main() {
    int N, i;
    struct Item it;
    float subtotal = 0.0;

    if (scanf("%d", &N) != 1)
        return 1;

    printf("\n--- RECEIPT ---\n");

    for (i = 1; i <= N; i++) {
        float itemTotal;

        if (scanf("%s %f %d", it.name, &it.price, &it.qty) != 3)
            return 1;

        itemTotal = calcItemTotal(it.price, it.qty);
        subtotal += itemTotal;

        printf("%s x %d = %.2f\n", it.name, it.qty, itemTotal);
    }

    float vat = subtotal * VAT_RATE;
    float grandTotal = subtotal + vat;

    printf("------------------\n");
    printf("Subtotal: %.2f\n", subtotal);
    printf("VAT (7%%): %.2f\n", vat);
    printf("Grand Total: %.2f\n", grandTotal);

    return 0;
}
