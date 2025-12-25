#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[20];
    int age;
    char gender;
    float gpa;
    struct Student *next;
};

// Function prototypes
void initNode(struct Student *s, char *n, int a, char g, float gp);
void moveNext(struct Student *cursor);
void printCurrent(struct Student *cursor);

int main() {
    struct Student *head, *current;

    // Create linked list manually
    head = malloc(sizeof(struct Student));
    initNode(head, "one", 6, 'M', 3.11);

    head->next = malloc(sizeof(struct Student));
    initNode(head->next, "two", 8, 'F', 3.22);

    head->next->next = malloc(sizeof(struct Student));
    initNode(head->next->next, "three", 10, 'M', 3.33);

    head->next->next->next = malloc(sizeof(struct Student));
    initNode(head->next->next->next, "four", 12, 'F', 3.44);

    // Point to first node
    current = head;

    // Try to move pointer (pass by value)
    moveNext(current);

    // Pointer in main is unchanged
    printCurrent(current);

    return 0;
}

// Initialize node data
void initNode(struct Student *s, char *n, int a, char g, float gp) {
    strcpy(s->name, n);
    s->age = a;
    s->gender = g;
    s->gpa = gp;
    s->next = NULL;
}

// Attempt to move pointer forward (won't affect main)
void moveNext(struct Student *cursor) {
    if (cursor->next != NULL) {
        cursor = cursor->next;
        printf("Inside function, moved to: %s\n", cursor->name);
    }
}

// Print current node from main
void printCurrent(struct Student *cursor) {
    printf("In main, still at: %s\n", cursor->name);
}
