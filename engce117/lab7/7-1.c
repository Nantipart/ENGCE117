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

struct LinkedList {
    struct studentNode *start;
    struct studentNode *now;
};

void initList(struct LinkedList *list) {
    list->start = NULL;
    list->now = NULL;
}

void InsNode(struct LinkedList *list, char n[], int a, char s, float g) {
    struct studentNode *p =
        (struct studentNode*) malloc(sizeof(struct studentNode));

    strcpy(p->name, n);
    p->age = a;
    p->sex = s;
    p->gpa = g;
    p->next = NULL;

    if (list->start == NULL)
        list->start = p;
    else {
        struct studentNode *t = list->start;
        while (t->next != NULL)
            t = t->next;
        t->next = p;
    }
}

void DelNode(struct LinkedList *list) {
    if (list->start == NULL) return;

    struct studentNode *temp = list->start;
    list->start = list->start->next;
    free(temp);
}

void GoNext(struct LinkedList *list) {
    if (list->now == NULL)
        list->now = list->start;
    else if (list->now->next != NULL)
        list->now = list->now->next;
}

int main() {

    struct LinkedList listA;
    struct LinkedList listB;
    struct LinkedList *listC;

    initList(&listA);
    initList(&listB);

    // listA
    InsNode(&listA, "one", 1, 'A', 1.1);
    InsNode(&listA, "two", 2, 'B', 2.2);
    InsNode(&listA, "three", 3, 'C', 3.3);

    // Scroll to "two".
    GoNext(&listA);  // now = one
    GoNext(&listA);  // now = two

    printf("%s %d %c %.2f\n",
           listA.now->name,
           listA.now->age,
           listA.now->sex,
           listA.now->gpa);

    // listB
    InsNode(&listB, "four", 4, 'D', 4.4);
    InsNode(&listB, "five", 5, 'E', 5.5);
    InsNode(&listB, "six", 6, 'F', 6.6);

    DelNode(&listB);  // ลบ four

    // Now listB = five -> six
    printf("%s %s\n",
           listB.start->next->name,   // six
           listB.start->name);        // five

    // Use pointer
    listC = &listA;
    printf("%s %d %c %.2f\n",
           listC->start->name,
           listC->start->age,
           listC->start->sex,
           listC->start->gpa);

    listC = &listB;
    printf("%s %s\n",
           listC->start->next->name,
           listC->start->name);

    return 0;
}
