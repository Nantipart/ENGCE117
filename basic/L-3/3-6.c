#include <stdio.h>

// Define structure
struct Transaction {
    char desc[50];
    float amount;
};

// function to process one transaction
void processTransaction(struct Transaction t,
                        float *income,
                        float *expense) {
    if (t.amount >= 0)
        *income += t.amount;
    else
        *expense += -t.amount;
}

int main() {
    int N;
    float totalIncome = 0.0;
    float totalExpense = 0.0;

    if (scanf("%d", &N) != 1 || N <= 0)
        return 1;

    struct Transaction t;

    // read and process immediately (no array needed)
    for (int i = 0; i < N; i++) {
        if (scanf("%f %s", &t.amount, t.desc) != 2)
            return 1;

        processTransaction(t, &totalIncome, &totalExpense);
    }

    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expense: %.2f\n", totalExpense);
    printf("Net Balance: %.2f\n", totalIncome - totalExpense);

    return 0;
}
