#include <stdio.h>

int main() {
    int zone = 0;
    float weight = 0.0;
    float shippingCost = 0.0;


    if (scanf("%d %f", &zone, &weight) != 2) {
        return 1; 
        // Exit if input is invalid
    }

    // Check zone using switch-case
    switch (zone) {
        case 1:
            if (weight <= 5.0) {
                shippingCost = 50.0;
            } else {
                // Weight > 5 kg
                shippingCost = 80.0;
            }
            break;

        case 2:
            if (weight <= 10.0) {
                shippingCost = 150.0;
            } else {
                // Weight > 10 kg
                shippingCost = 250.0;
            }
            break;

        case 3:
            // Fixed rate
            shippingCost = 500.0;
            break;

        default:
            printf("Invalid Zone Code\n");
            return 0; 
            // Terminate program immediately
    }

    // Print total cost formatted to 2 decimal places
    printf("%.2f\n", shippingCost);

    return 0;
}