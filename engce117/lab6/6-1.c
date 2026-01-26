#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
    struct studentNode *prev;
} Student;

/* ===== helper ===== */
Student* createNode(char *name, int age, char sex, float gpa);

/* ===== core functions ===== */
Student* AppendNode(Student **head, char *name, int age, char sex, float gpa);
void InsertBefore(Student **head, Student *current,
                  char *name, int age, char sex, float gpa);
void RemoveCurrent(Student **head, Student **current);
void MoveBackward(Student **current);
void PrintList(Student *ptr);

/* ============================= */

Student* createNode(char *name, int age, char sex, float gpa) {
    Student *node = malloc(sizeof(Student));
    strcpy(node->name, name);
    node->age = age;
    node->sex = sex;
    node->gpa = gpa;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

Student* AppendNode(Student **head, char *name, int age, char sex, float gpa) {
    Student *node = createNode(name, age, sex, gpa);

    if (*head == NULL) {
        *head = node;
        return node;
    }

    Student *tail = *head;
    for (; tail->next != NULL; tail = tail->next);

    tail->next = node;
    node->prev = tail;

    return node;
}

void InsertBefore(Student **head, Student *current,
                  char *name, int age, char sex, float gpa) {
    if (current == NULL) return;

    Student *node = createNode(name, age, sex, gpa);
    node->next = current;
    node->prev = current->prev;

    if (current->prev != NULL)
        current->prev->next = node;
    else
        *head = node;

    current->prev = node;
}

void RemoveCurrent(Student **head, Student **current) {
    if (*current == NULL) return;

    Student *del = *current;

    if (del->prev != NULL)
        del->prev->next = del->next;
    else
        *head = del->next;

    if (del->next != NULL) {
        del->next->prev = del->prev;
        *current = del->next;
    } else {
        *current = del->prev;
    }

    free(del);
}

void MoveBackward(Student **current) {
    if (*current && (*current)->prev)
        *current = (*current)->prev;
}

void PrintList(Student *ptr) {
    for (; ptr != NULL; ptr = ptr->next)
        printf("%s ", ptr->name);
    printf("\n");
}
/* ============================= */