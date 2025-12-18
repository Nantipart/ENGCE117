#include <stdio.h>

struct Student {
    int id;
    int math_score;
    int science_score;
    int english_score;
    int total_score;
};

// Function prototypes declaration.
char calculate_grade(int total_score);
void calculate_average(int total_score, float *avg);

int main() {
    struct Student student_info;
    char final_grade;
    float final_average;

    printf("Enter Student ID: ");
    scanf("%d", &student_info.id);

    printf("Enter Math Score (out of 100): ");
    scanf("%d", &student_info.math_score);

    printf("Enter Science Score (out of 100): ");
    scanf("%d", &student_info.science_score);

    printf("Enter English Score (out of 100): ");
    scanf("%d", &student_info.english_score);

    // Calculate total score from three subjects.
    student_info.total_score = student_info.math_score + student_info.science_score + student_info.english_score;

    // Call function to determine the letter grade.
    final_grade = calculate_grade(student_info.total_score);

    // Call function to calculate average score using pass-by-reference.
    calculate_average(student_info.total_score, &final_average);

    printf("\n--- STUDENT ACADEMIC REPORT ---\n");
    printf("Student ID: %d\n", student_info.id);
    printf("Math Score: %d, Science Score: %d, English Score: %d\n", student_info.math_score, student_info.science_score, student_info.english_score);
    printf("Total Score: %d\n", student_info.total_score);
    printf("Average Score: %.2f\n", final_average);
    printf("Final Grade: %c\n", final_grade);

    return 0;
}

// Function to determine grade based on total score.
char calculate_grade(int total_score) {
    if (total_score >= 250) {
        return 'A';
    } else if (total_score >= 200) {
        return 'B';
    } else {
        return 'C';
    }
}

// Function to calculate average and update the variable via pointer.
void calculate_average(int total_score, float *avg) {
    *avg = (float)total_score / 3.0;
}