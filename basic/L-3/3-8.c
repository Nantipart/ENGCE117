#include <stdio.h>

// Define structure
struct Campaign {
    char name[50];
    float price;
    int sales;
    float adCost;
};

// Function to get commission rate
float getRate(int sales) {
    if (sales >= 20)
        return 0.20;
    else if (sales >= 10)
        return 0.15;
    else
        return 0.10;
}

int main() {
    int N;
    struct Campaign c;

    if (scanf("%d", &N) != 1)
        return 1;

    for (int i = 1; i <= N; i++) {
        float revenue, rate, net;

        if (scanf("%s %f %d %f",
                  c.name, &c.price, &c.sales, &c.adCost) != 4)
            return 1;

        revenue = c.price * c.sales;
        rate = getRate(c.sales);
        net = (revenue * rate) - c.adCost;

        printf("--- Campaign: %s ---\n", c.name);
        printf("Sales: %d, Ad Spend: %.2f\n", c.sales, c.adCost);
        printf("Rate Used: %.0f%%\n", rate * 100.0);
        printf("Calculation: (%.2f * %.0f%%) - %.2f = %.2f\n",
               revenue, rate * 100.0, c.adCost, net);
        printf("Net Result: %.2f\n", net);
    }

    return 0;
}
