#include <stdio.h>

float getAPR(float balance) {
    return (balance < 1000.0) ? 0.01 : 0.025;
}

int main() {
    int periods, cmd, month;
    float startBalance, penaltyFee, amount;
    float balance, totalPenalty = 0.0;

    if (scanf("%f %f %d", &startBalance, &penaltyFee, &periods) != 3)
        return 1;

    balance = startBalance;
    printf("Starting Balance: %.2f\n", balance);

    for (month = 1; month <= periods; month++) {
        if (scanf("%d %f", &cmd, &amount) != 2)
            break;

        printf("--- Month %d ---\n", month);

        if (cmd == 1) {                      // deposit
            balance += amount;
            printf("Deposit: %.2f\n", amount);
        }
        else if (cmd == 2) {                 // withdraw
            if (amount <= balance) {
                balance -= amount;
                printf("Withdrawal: %.2f\n", amount);
            } else {
                totalPenalty += penaltyFee;
                printf("WITHDRAWAL FAILED. Penalty %.2f applied.\n", penaltyFee);
            }
        }
        else if (cmd == 3) {                 // interest
            float apr = getAPR(balance);
            float interest = balance * (apr / 12.0);
            balance += interest;
            printf("Interest: %.2f (Rate: %.1f%%)\n", interest, apr * 100);
        }
        else {
            printf("Error: Invalid Command.\n");
        }
    }

    printf("Final Balance: %.2f\n", balance);
    printf("Total Penalties: %.2f\n", totalPenalty);
    return 0;
}
