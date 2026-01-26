#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct Node *next;
    struct Node *prev;
} Node;

/* ===== utility ===== */
Node* newStudent(char *name, int age, char sex, float gpa);

/* ===== list operations ===== */
Node* addTail(Node **start, char *name, int age, char sex, float gpa);
void insertFront(Node **start, Node *pos,
                 char *name, int age, char sex, float gpa);
void deleteNow(Node **start, Node **pos);
void stepBack(Node **pos);
void display(Node *walk);

/* ============================ */

Node* newStudent(char *name, int age, char sex, float gpa) {
    Node *p = (Node*)malloc(sizeof(Node));
    if (p == NULL) return NULL;

    strcpy(p->name, name);
    p->age = age;
    p->sex = sex;
    p->gpa = gpa;
    p->next = NULL;
    p->prev = NULL;

    return p;
}

Node* addTail(Node **start, char *name, int age, char sex, float gpa) {
    Node *node = newStudent(name, age, sex, gpa);

    if (*start == NULL) {
        *start = node;
        return node;
    }

    Node *walk = *start;
    while (walk->next)
        walk = walk->next;

    walk->next = node;
    node->prev = walk;

    return node;
}

void insertFront(Node **start, Node *pos,
                 char *name, int age, char sex, float gpa) {
    if (pos == NULL) return;

    Node *node = newStudent(name, age, sex, gpa);
    node->next = pos;
    node->prev = pos->prev;

    if (pos->prev)
        pos->prev->next = node;
    else
        *start = node;

    pos->prev = node;
}

void deleteNow(Node **start, Node **pos) {
    if (*pos == NULL) return;

    Node *tmp = *pos;

    if (tmp->prev)
        tmp->prev->next = tmp->next;
    else
        *start = tmp->next;

    if (tmp->next) {
        tmp->next->prev = tmp->prev;
        *pos = tmp->next;
    } else {
        *pos = tmp->prev;
    }

    free(tmp);
}

void stepBack(Node **pos) {
    if (*pos && (*pos)->prev)
        *pos = (*pos)->prev;
}

void display(Node *walk) {
    while (walk) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}