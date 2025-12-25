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
struct studentNode *createNode(char n[], int a, char s, float g);
void moveNext(struct studentNode **current);

int main() {
    struct studentNode *head, *cursor;

    // Build linked list
    head = createNode("one", 6, 'M', 3.11);
    head->next = createNode("two", 8, 'F', 3.22);
    head->next->next = createNode("three", 10, 'M', 3.33);

    // Set cursor at head
    cursor = head;

    // Move cursor to next node
    moveNext(&cursor);

    // Display result
    printf("Current student: %s\n", cursor->name);

    return 0;
}

// Create and initialize a node
struct studentNode *createNode(char n[], int a, char s, float g) {
    struct studentNode *node;
    node = (struct studentNode *)malloc(sizeof(struct studentNode));

    strcpy(node->name, n);
    node->age = a;
    node->sex = s;
    node->gpa = g;
    node->next = NULL;

    return node;
}

// Move pointer to next node using double pointer
void moveNext(struct studentNode **current) {
    if (*current != NULL && (*current)->next != NULL) {
        *current = (*current)->next;
    }
}
