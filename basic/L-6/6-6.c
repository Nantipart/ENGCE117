#include <stdio.h>

int calculateBalance(const int *list, int size, int *resultStatus);

int main() {
    const int N = 5;
    int transactions[N];
    int finalStatus;
    int finalBalance;
    int i;

    printf("Enter transactions (income +, expense -)\n");
    for (i = 0; i < N; i++) {
        printf("Transaction %d: ", i + 1);
        scanf("%d", &transactions[i]);
    }

    finalBalance = calculateBalance(transactions, N, &finalStatus);

    printf("\nTransactions: ");
    for (i = 0; i < N; i++) {
        printf("%d ", transactions[i]);
    }

    printf("\nBalance: %d\n", finalBalance);
    printf("Status: %s\n", finalStatus ? "Profit" : "Loss");

    return 0;
}

int calculateBalance(const int *list, int size, int *resultStatus) {
    int sum = 0;

    while (size--) {
        sum += *list;
        list++;
    }

    *resultStatus = (sum >= 0);
    return sum;
}
