#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

/* Function prototypes */
void ShowAll(struct studentNode **walk);
void InsNode(struct studentNode **pos, char *name, int age, char sex, float gpa);
void DelNode(struct studentNode **pos);
void GoNext(struct studentNode ***pos);

/* ===================== MAIN ===================== */
int main() {
    struct studentNode *start = NULL;
    struct studentNode **now = &start;

    InsNode(now, "one", 6, 'M', 3.11);
    ShowAll(&start);

    InsNode(now, "two", 8, 'F', 3.22);
    ShowAll(&start);

    GoNext(&now);
    InsNode(now, "three", 10, 'M', 3.33);
    ShowAll(&start);

    InsNode(now, "four", 12, 'F', 3.44);
    ShowAll(&start);

    GoNext(&now);
    DelNode(now);
    ShowAll(&start);

    return 0;
}

/* ===================== FUNCTIONS ===================== */

void InsNode(struct studentNode **pos, char *name, int age, char sex, float gpa) {
    struct studentNode *newNode = malloc(sizeof(struct studentNode));

    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;

    newNode->next = *pos;
    *pos = newNode;
}

void DelNode(struct studentNode **pos) {
    if (*pos == NULL) return;

    struct studentNode *temp = *pos;
    *pos = temp->next;
    free(temp);
}

void GoNext(struct studentNode ***pos) {
    if (**pos != NULL) {
        *pos = &((**pos)->next);
    }
}

void ShowAll(struct studentNode **walk) {
    struct studentNode *ptr = *walk;
    while (ptr != NULL) {
        printf("%s ", ptr->name);
        ptr = ptr->next;
    }
    printf("\n");
}
