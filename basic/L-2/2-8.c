#include <stdio.h>

int main() {
    int N, i;
    int studentId, score, totalClasses, absentClasses;
    float attendancePercent;
    int passCount = 0;
    int failCount = 0;

    // Receive number of students
    if (scanf("%d", &N) != 1) {
        return 1;
    }

    // Loop through each student
    for (i = 0; i < N; i++) {
        // Receive student details
        if (scanf("%d %d %d %d", &studentId, &score, &totalClasses, &absentClasses) != 4) {
            break;
        }

        // Calculate attendance percentage
        attendancePercent = (float)(totalClasses - absentClasses) / totalClasses * 100.0;

        // Check PASS conditions: Score >= 50 AND Attendance >= 75%
        if (score >= 50 && attendancePercent >= 75.0) {
            printf("Student %d: PASS\n", studentId);
            passCount++; // Increment pass counter
        } else {
            // Handle FAIL cases and identify the reason
            printf("Student %d: FAIL ", studentId);
            
            if (score < 50 && attendancePercent < 75.0) {
                // Failed both conditions
                printf("(Reason: Both Score and Attendance)\n");
            } else if (score < 50) {
                // Failed only score
                printf("(Reason: Score)\n");
            } else {
                // Failed only attendance
                printf("(Reason: Attendance)\n");
            }
            failCount++; // Increment fail counter
        }
    }

    // Print summary section (Pre-code provided)
    printf("\n--- Summary ---\n");
    printf("Total PASS: %d\n", passCount);
    printf("Total FAIL: %d\n", failCount);

    return 0;
}