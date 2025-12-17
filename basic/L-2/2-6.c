#include <stdio.h>

int main() {
    int N_MONTHS, month;
    int successCount = 0;
    float dailyDeposit, monthlyTotal;

    if (scanf("%d", &N_MONTHS) != 1)
        return 1;

    for (month = 1; month <= N_MONTHS; month++) {
        monthlyTotal = 0.0;

        while (1) {
            if (scanf("%f", &dailyDeposit) != 1)
                return 1;

            if (dailyDeposit == 0.00)     // end of daily input
                break;

            monthlyTotal += dailyDeposit; // accumulate
        }

        printf("Month %d Total: %.2f\n", month, monthlyTotal);

        if (monthlyTotal >= 500.00)
            successCount++;
    }

    printf("Success Count: %d\n", successCount);
    return 0;
}
