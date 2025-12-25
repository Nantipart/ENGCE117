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

// Function prototypes
void FillNode(struct studentNode *n, char name[], int age, char sex, float gpa);
void MoveCursor(struct studentNode ***cursor);

int main() {
    struct studentNode *head, **cursor;

    // Create nodes
    head = (struct studentNode *)malloc(sizeof(struct studentNode));
    FillNode(head, "one", 6, 'M', 3.11);

    head->next = (struct studentNode *)malloc(sizeof(struct studentNode));
    FillNode(head->next, "two", 8, 'F', 3.22);

    head->next->next = (struct studentNode *)malloc(sizeof(struct studentNode));
    FillNode(head->next->next, "three", 10, 'M', 3.33);

    head->next->next->next = (struct studentNode *)malloc(sizeof(struct studentNode));
    FillNode(head->next->next->next, "four", 12, 'F', 3.44);

    cursor = &head;

    printf("Before move: %s\n", (*cursor)->name);

    // Triple pointer usage
    MoveCursor(&cursor);

    printf("After move:  %s\n", (*cursor)->name);

    return 0;
}

// Store data into node
void FillNode(struct studentNode *n, char name[], int age, char sex, float gpa) {
    strcpy(n->name, name);
    n->age = age;
    n->sex = sex;
    n->gpa = gpa;
    n->next = NULL;
}

// Triple pointer function
void MoveCursor(struct studentNode ***cursor) {
    if (**cursor && (**cursor)->next) {
        **cursor = (**cursor)->next;
    }
}

