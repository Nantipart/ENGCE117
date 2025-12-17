#include <stdio.h>
#include <stdlib.h>

// Student structure
struct Student {
    int id;
    float score;
    char name[50];
};

int main() {
    int N;
    int pass = 0, fail = 0;

    if (scanf("%d", &N) != 1 || N <= 0)
        return 1;

    // dynamic allocation instead of VLA
    struct Student *students = malloc(N * sizeof(struct Student));
    if (!students)
        return 1;

    for (int i = 0; i < N; i++) {
        // read input
        if (scanf("%d %f %49s",
                  &students[i].id,
                  &students[i].score,
                  students[i].name) != 3) {
            free(students);
            return 1;
        }

        // count pass / fail immediately
        if (students[i].score >= 60.0)
            pass++;
        else
            fail++;
    }

    printf("Pass Count: %d\n", pass);
    printf("Fail Count: %d\n", fail);

    free(students);
    return 0;
}
