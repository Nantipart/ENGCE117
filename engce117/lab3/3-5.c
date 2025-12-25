#include <stdio.h>
#include <stdlib.h>

#define STUDENTS_PER_ROOM 10

struct student {
    char name[20];
    int age;
    char sex;
    float gpa;
};

/* Function Prototype */
struct student (*inputStudents(int *totalRooms))[STUDENTS_PER_ROOM];

int main() {
    struct student (*classroom)[STUDENTS_PER_ROOM];
    int rooms;

    classroom = inputStudents(&rooms);

    /* Simple verification output */
    printf("\n--- SUMMARY ---\n");
    printf("Total classrooms: %d\n", rooms);
    printf("First student name: %s\n", classroom[0][0].name);
    printf("First student GPA: %.2f\n", classroom[0][0].gpa);

    free(classroom);
    return 0;
}

/* Function Definition */
struct student (*inputStudents(int *totalRooms))[STUDENTS_PER_ROOM] {
    struct student (*data)[STUDENTS_PER_ROOM];
    int r, s;

    printf("Enter total classrooms: ");
    scanf("%d", totalRooms);

    data = malloc((*totalRooms) * sizeof *data);
    if (data == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (r = 0; r < *totalRooms; r++) {
        printf("\nRoom %d\n", r + 1);
        for (s = 0; s < STUDENTS_PER_ROOM; s++) {
            printf("Student %d (Name Age Sex GPA): ", s + 1);
            scanf("%s %d %c %f",
                  data[r][s].name,
                  &data[r][s].age,
                  &data[r][s].sex,
                  &data[r][s].gpa);
        }
    }

    return data;
}
