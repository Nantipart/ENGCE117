#include <stdio.h>

#define STUDENTS 5

int main() {
    int marks[STUDENTS];
    int total = 0;
    float avg;
    int higherCount = 0;
    int idx;

    // Input scores
    for (idx = 0; idx < STUDENTS; idx++) {
        scanf("%d", &marks[idx]);
        total += marks[idx];
    }

    // Calculate average
    avg = total / (float)STUDENTS;

    // Count scores above average
    for (idx = 0; idx < STUDENTS; idx++) {
        if (marks[idx] > avg) {
            higherCount++;
        }
    }

    // Display report
    printf("=== SCORE SUMMARY ===\n");
    printf("Scores: ");
    for (idx = 0; idx < STUDENTS; idx++) {
        printf("%d ", marks[idx]);
    }
    printf("\n");

    printf("Sum: %d\n", total);
    printf("Average: %.2f\n", avg);
    printf("Above Average Count: %d\n", higherCount);

    return 0;
}
