#include <stdio.h>

/* Employee structure */
struct Employee {
    int id;
    int salary;
    int bonus;
};

/* Function prototype */
int netIncome(struct Employee e);

int main() {
    struct Employee emp;
    int net;

    // Input
    scanf("%d", &emp.id);
    scanf("%d", &emp.salary);
    scanf("%d", &emp.bonus);

    // Calculate net income
    net = netIncome(emp);

    // Output
    printf("\n--- EMPLOYEE SUMMARY ---\n");
    printf("Employee ID: %d\n", emp.id);
    printf("Base Salary: %d\n", emp.salary);
    printf("Bonus Earned: %d\n", emp.bonus);
    printf("Net Income: %d\n", net);

    return 0;
}

/* Calculate net income after tax */
int netIncome(struct Employee e) {
    int total = e.salary + e.bonus;
    float taxRate;

    if (total > 30000)
        taxRate = 0.10;
    else
        taxRate = 0.05;

    return (int)(total * (1 - taxRate));
}
