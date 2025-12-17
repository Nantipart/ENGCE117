#include <stdio.h>

int main() {
    int termCode;
    float investmentAmount, rate, interest;

    if (scanf("%d %f", &termCode, &investmentAmount) != 2)
        return 1;

    if (termCode == 1)
        rate = (investmentAmount < 5000) ? 0.03 : 0.04;
    else if (termCode == 2)
        rate = (investmentAmount < 10000) ? 0.05 : 0.065;
    else if (termCode == 3)
        rate = 0.08;
    else {
        printf("Invalid Term Code\n");
        return 0;
    }

    interest = investmentAmount * rate;
    printf("%.2f\n", interest);

    return 0;
}
