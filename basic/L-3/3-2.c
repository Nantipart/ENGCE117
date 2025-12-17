#include <stdio.h>
#include <stdlib.h>

// Student structure
struct Student {
    int id;
    float score;
    char name[50];
};

// read student data
int readStudent(struct Student *s) {
    return scanf("%d %f %49s", &s->id, &s->score, s->name) == 3;
}

// print student data
void printStudent(struct Student s) {
    printf("Student ID: %d\n", s.id);
    printf("Name: %s\n", s.name);
    printf("Score: %.2f\n", s.score);
    printf("--------------------\n");
}

int main() {
    int N, i;

    if (scanf("%d", &N) != 1 || N <= 0)
        return 1;

    // dynamic allocation instead of VLA
    struct Student *students = malloc(N * sizeof(struct Student));
    if (!students)
        return 1;

    for (i = 0; i < N; i++) {
        if (!readStudent(&students[i])) {
            free(students);
            return 1;
        }
    }

    printf("\n--- Student List ---\n");
    for (i = 0; i < N; i++)
        printStudent(students[i]);

    free(students);
    return 0;
}
