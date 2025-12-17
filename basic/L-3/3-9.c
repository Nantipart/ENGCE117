#include <stdio.h>

// Decide spend amount based on remaining budget
float calcSpend(float budget) {
    if (budget >= 500.0) return 100.0;
    if (budget >= 100.0) return 50.0;
    if (budget > 0.0)    return 20.0;
    return 0.0;
}

int main() {
    int days, d = 1;
    float budget, spend;

    if (scanf("%f %d", &budget, &days) != 2)
        return 1;

    printf("Day | Spend | Remaining\n");
    printf("----------------------\n");

    while (d <= days) {
        spend = calcSpend(budget);

        // prevent overspend
        if (spend > budget)
            spend = budget;

        budget -= spend;

        printf("%d | %.2f | %.2f\n", d, spend, budget);
        d++;
    }

    printf("----------------------\n");
    printf("Final Budget: %.2f\n", budget);
    return 0;
}
