#include <stdio.h>

#define NUM_EMPLOYEES 4

struct Employee {
    int id;
    int salary;
};

void find_min_max_salary(struct Employee emps[], int size, int *max, int *min);

int main() {
    struct Employee staff_data[NUM_EMPLOYEES];
    int max_salary;
    int min_salary;
    int i;

    printf("Enter data for %d employees:\n", NUM_EMPLOYEES);
    for (i = 0; i < NUM_EMPLOYEES; i++) {
        printf("--- Employee %d ---\n", i + 1);
        printf("Enter ID: ");
        scanf("%d", &staff_data[i].id);
        printf("Enter Salary: ");
        scanf("%d", &staff_data[i].salary);
    }

    // Call function to determine min and max salaries using pass-by-reference.
    find_min_max_salary(staff_data, NUM_EMPLOYEES, &max_salary, &min_salary);

    printf("\n--- EMPLOYEE SALARY SUMMARY ---\n");
    printf("ID     | Salary\n");
    printf("-------|---------\n");
    for (i = 0; i < NUM_EMPLOYEES; i++) {
        printf("%-6d | %d\n", staff_data[i].id, staff_data[i].salary);
    }
    printf("\nMaximum Salary Found: %d\n", max_salary);
    printf("Minimum Salary Found: %d\n", min_salary);

    return 0;
}

void find_min_max_salary(struct Employee emps[], int size, int *max, int *min) {
    int i;

    // Initialize max and min with the first employee's salary.
    *max = emps[0].salary;
    *min = emps[0].salary;

    for (i = 1; i < size; i++) {
        // Update max pointer if current salary is higher.
        if (emps[i].salary > *max) {
            *max = emps[i].salary;
        }
        // Update min pointer if current salary is lower.
        if (emps[i].salary < *min) {
            *min = emps[i].salary;
        }
    }
}