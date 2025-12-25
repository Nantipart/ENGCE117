#include <stdio.h>

//Student information structure
struct StudentInfo {
    char name[20];
    int age;
    char gender;
    float gpa;
};


void adjust_gpa(struct StudentInfo *s);

int main() {
    struct StudentInfo student1;

    /* Initial values */
    student1.gender = 'M';
    student1.gpa = 3.00;

    /* Update GPA via pointer */
    adjust_gpa(&student1);

    /* Display updated GPA */
    printf("Updated GPA: %.2f\n", student1.gpa);

    return 0;
}

/* Function definition */
void adjust_gpa(struct StudentInfo *s) {
    float rate;

    /* Determine increase rate */
    if (s->gender == 'M') {
        rate = 1.10;
    } else {
        rate = 1.20;
    }

    /* Apply GPA adjustment */
    s->gpa = s->gpa * rate;
}
