#include <stdio.h>

struct StudentData {
    char name[20];
    int age;
    char gender;
    float gpa;
};

struct StudentData revise_gpa(struct StudentData s);

int main() {
    struct StudentData s1;

    s1.gender = 'M';
    s1.gpa = 3.00;

    /* Update GPA by receiving returned structure */
    s1 = revise_gpa(s1);

    /* Display final GPA */
    printf("Final GPA: %.2f\n", s1.gpa);

    return 0;
}

/* Function to modify and return student structure */
struct StudentData revise_gpa(struct StudentData s) {
    float factor;

    /* Decide adjustment factor */
    if (s.gender == 'M') {
        factor = 1.10;
    } else {
        factor = 1.20;
    }

    /* Apply GPA increase */
    s.gpa = s.gpa * factor;

    return s;
}
