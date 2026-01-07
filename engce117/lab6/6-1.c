#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
    struct studentNode *back;
};

struct studentNode* AddNode(struct studentNode **start,
                            char *name, int age, char sex, float gpa);

void InsNode(struct studentNode **start, struct studentNode *now,
             char *name, int age, char sex, float gpa);

void DelNode(struct studentNode **start, struct studentNode **now);
void GoBack(struct studentNode **now);
void ShowAll(struct studentNode *walk);

/* ========================= */

struct studentNode* AddNode(struct studentNode **start,
                            char *name, int age, char sex, float gpa) {

    struct studentNode *newNode = malloc(sizeof(struct studentNode));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = NULL;
    newNode->back = NULL;

    if (*start == NULL) {
        *start = newNode;
    } else {
        struct studentNode *temp = *start;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->back = temp;
    }
    return newNode;
}

void InsNode(struct studentNode **start, struct studentNode *now,
             char *name, int age, char sex, float gpa) {

    struct studentNode *newNode = malloc(sizeof(struct studentNode));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;

    newNode->next = now;
    newNode->back = now->back;

    if (now->back != NULL)
        now->back->next = newNode;
    else
        *start = newNode;

    now->back = newNode;
}

void DelNode(struct studentNode **start, struct studentNode **now) {
    if (*now == NULL) return;

    struct studentNode *temp = *now;

    if (temp->back != NULL)
        temp->back->next = temp->next;
    else
        *start = temp->next;

    if (temp->next != NULL) {
        temp->next->back = temp->back;
        *now = temp->next;
    } else {
        *now = temp->back;
    }

    free(temp);
}

void GoBack(struct studentNode **now) {
    if (*now != NULL && (*now)->back != NULL)
        *now = (*now)->back;
}

void ShowAll(struct studentNode *walk) {
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}
/* ========================= MAIN ========================= */