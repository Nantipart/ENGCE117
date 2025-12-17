#include <stdio.h>

int main() {
    float principal, monthlyPayment;
    float interest;
    int month = 0;

    const float INTEREST_RATE = 0.01;
    const float PENALTY = 10.0;

    if (scanf("%f %f", &principal, &monthlyPayment) != 2)
        return 1;

    while (principal > 0) {
        month++;

        // calculate interest
        interest = principal * INTEREST_RATE;
        principal += interest;

        // penalty if payment < interest
        if (monthlyPayment < interest)
            principal += PENALTY;

        // make payment
        principal -= monthlyPayment;

        if (principal < 0)
            principal = 0;

        printf("Month %d: Remaining Debt = %.2f\n", month, principal);
    }

    return 0;
}
