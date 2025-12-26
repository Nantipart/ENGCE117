#include <stdio.h>

#define PERIOD 3

enum Result {
    LOSS = 0,
    PROFIT = 1
};

void input_data(int arr[], int n, const char *label);
long sum_array(int arr[], int n);
int evaluate_business(int income[], int cost[], int n, int *net_result);

int main() {
    int revenue[PERIOD];
    int expense[PERIOD];
    int net_profit = 0;
    int status;

    input_data(revenue, PERIOD, "REVENUE");
    input_data(expense, PERIOD, "EXPENSE");

    status = evaluate_business(revenue, expense, PERIOD, &net_profit);

    printf("\n--- 3 MONTH FINANCIAL ANALYSIS REPORT ---\n");
    printf("TOTAL REVENUE : %ld\n", sum_array(revenue, PERIOD));
    printf("TOTAL EXPENSE : %ld\n", sum_array(expense, PERIOD));
    printf("NET PROFIT    : %d\n", net_profit);

    printf("BUSINESS STATUS: ");
    if (status == PROFIT) {
        printf("PROJECT IS PROFITABLE\n");
    } else {
        printf("PROJECT IS UNPROFITABLE\n");
    }

    return 0;
}

/* ===== Functions ===== */

void input_data(int arr[], int n, const char *label) {
    printf("\nEnter %d months of %s:\n", n, label);
    for (int i = 0; i < n; i++) {
        printf("Month %d %s: ", i + 1, label);
        scanf("%d", &arr[i]);
    }
}

long sum_array(int arr[], int n) {
    long total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

int evaluate_business(int income[], int cost[], int n, int *net_result) {
    *net_result = 0;

    for (int i = 0; i < n; i++) {
        *net_result += income[i] - cost[i];
    }

    return (*net_result >= 0) ? PROFIT : LOSS;
}
