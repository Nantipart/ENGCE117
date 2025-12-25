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
struct studentNode *newNode(char name[], int age, char sex, float gpa);
void advanceNode(struct studentNode **ptr);

int main() {
    struct studentNode *head;
    struct studentNode **cursorPtr;

    // Build linked list
    head = newNode("one", 6, 'M', 3.11);
    head->next = newNode("two", 8, 'F', 3.22);
    head->next->next = newNode("three", 10, 'M', 3.33);
    head->next->next->next = newNode("four", 12, 'F', 3.44);

    // Pointer to pointer
    cursorPtr = &head;

    // Move pointer to next node
    advanceNode(cursorPtr);

    // Display result in main (cleaner design)
    printf("Current student: %s\n", (*cursorPtr)->name);

    return 0;
}

// Create and initialize a node
struct studentNode *newNode(char name[], int age, char sex, float gpa) {
    struct studentNode *n;
    n = (struct studentNode *)malloc(sizeof(struct studentNode));

    strcpy(n->name, name);
    n->age = age;
    n->sex = sex;
    n->gpa = gpa;
    n->next = NULL;

    return n;
}

// Move pointer using double pointer
void advanceNode(struct studentNode **ptr) {
    if (*ptr != NULL && (*ptr)->next != NULL) {
        *ptr = (*ptr)->next;
    }
}
