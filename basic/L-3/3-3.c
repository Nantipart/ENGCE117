#include <stdio.h>
#include <stdlib.h>

// Student structure
struct Student {
    int id;
    float score;
    char name[50];
};

// function to read student data
int readStudent(struct Student *s) {
    return scanf("%d %f %49s", &s->id, &s->score, s->name) == 3;
}

// function to calculate average score
float calcAverage(struct Student *arr, int n) {
    float sum = 0.0;
    for (int i = 0; i < n; i++)
        sum += arr[i].score;
    return (n > 0) ? sum / n : 0.0;
}

int main() {
    int N;

    printf("Enter number of students: ");
    if (scanf("%d", &N) != 1 || N <= 0)
        return 1;

    // dynamic allocation instead of VLA
    struct Student *students = malloc(N * sizeof(struct Student));
    if (!students)
        return 1;

    for (int i = 0; i < N; i++) {
        printf("Enter details for student %d (ID Score Name): ", i + 1);
        if (!readStudent(&students[i])) {
            free(students);
            return 1;
        }
    }

    float avg = calcAverage(students, N);

    printf("\n--- Class Result ---\n");
    printf("Average Score: %.2f\n", avg);

    free(students);
    return 0;
}
