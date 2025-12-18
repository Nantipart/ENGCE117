#include <stdio.h>

int main() {
    int salary;
    float tax;
    float net;

    // Read gross salary
    scanf("%d", &salary);

    // Determine tax directly
    if (salary < 20000) {
        tax = 0.0;
    } else if (salary < 50000) {
        tax = salary * 0.05;
    } else {
        tax = salary * 0.10;
    }

    // Calculate net salary
    net = salary - tax;

    // Display result
    printf("--- SALARY SUMMARY ---\n");
    printf("Gross Salary: %d THB\n", salary);
    printf("Tax Deducted: %.2f THB\n", tax);
    printf("Net Salary: %.2f THB\n", net);

    return 0;
}
