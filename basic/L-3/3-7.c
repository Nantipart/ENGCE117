#include <stdio.h>

// Define structure
struct SalesRecord {
    char name[50];
    float target;
    float actual;
};

// Function to calculate commission for one salesperson
float calculateCommission(float target, float actual) {
    float commission = actual * 0.10;

    if (actual >= target * 1.20) {
        commission += 200.0;
    } else if (actual >= target) {
        commission += 50.0;
    } else if (actual < target * 0.90) {
        commission -= 100.0;
    }

    return commission;
}

int main() {
    int N;
    float grandTotal = 0.0;
    struct SalesRecord record;

    if (scanf("%d", &N) != 1)
        return 1;

    for (int i = 0; i < N; i++) {
        if (scanf("%f %f %s",
                  &record.target,
                  &record.actual,
                  record.name) != 3)
            return 1;

        grandTotal += calculateCommission(record.target, record.actual);
    }

    printf("Grand Total Commission: %.2f\n", grandTotal);
    return 0;
}
