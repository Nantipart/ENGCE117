#include <stdio.h>

int main() {
    int N_MONTHS, m;
    int successCount = 0;
    float deposit, sum;

    if (scanf("%d", &N_MONTHS) != 1)
        return 1;

    for (m = 1; m <= N_MONTHS; m++) {
        sum = 0.0;

        do {
            if (scanf("%f", &deposit) != 1)
                return 1;

            if (deposit > 0)
                sum += deposit;

        } while (deposit != 0.00);

        printf("Month %d Total: %.2f\n", m, sum);

        successCount += (sum >= 500.00);   // count success
    }

    printf("Success Count: %d\n", successCount);
    return 0;
}
