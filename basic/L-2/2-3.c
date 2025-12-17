#include <stdio.h>

int main() {
    int termCode;
    float investmentAmount;
    float aprRate = 0.0;
    float totalInterest = 0.0;

    if (scanf("%d %f", &termCode, &investmentAmount) != 2) {
        return 1; // Exit if input is invalid
    }

    switch (termCode) {
        case 1: 
            // Check investment amount condition for Term 1
            if (investmentAmount < 5000) {
                aprRate = 0.03; // 3.0% APR
            } else {
                aprRate = 0.04; // 4.0% APR
            }
            break;

        case 2:
            // Check investment amount condition for Term 2
            if (investmentAmount < 10000) {
                aprRate = 0.05; // 5.0% APR
            } else {
                aprRate = 0.065; // 6.5% APR
            }
            break;

        case 3: 
            // Fixed rate for Term 3
            aprRate = 0.08; // 8.0% APR
            break;

        default:
            break;
    }
    if (termCode >= 1 && termCode <= 3) {
        totalInterest = investmentAmount * aprRate;
        printf("%.2f\n", totalInterest);
    } else {
        printf("Invalid Term Code\n");
    }

    return 0;
}