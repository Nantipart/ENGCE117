#include <stdio.h>

int main() {
    int categoryCode;
    float price_before_vat, totalBill = 0.0, vatAmount = 0.0;

    // read input
    if (scanf("%f %d", &price_before_vat, &categoryCode) != 2)
        return 1;

    // calculate by category
    if (categoryCode == 1)          
    // Standard 7%
        totalBill = price_before_vat * 1.07;
    else if (categoryCode == 2)     
    // Zero Rated 0%
        totalBill = price_before_vat;
    else if (categoryCode == 3)     
    // Luxury 15%
        totalBill = price_before_vat * 1.15;
    else {
        printf("Invalid Category\n");
        printf("Total Price: 0.00\n");
        return 0;
    }

    vatAmount = totalBill - price_before_vat;

    printf("VAT Amount: %.2f\n", vatAmount);
    printf("Total Price: %.2f\n", totalBill);

    return 0;
}
