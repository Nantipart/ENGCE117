#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode
{
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
    struct studentNode *back;
};

/* prototypes */
struct studentNode *AddNode(struct studentNode **start,
                            char name[], int age, char sex, float gpa);
void InsNode(struct studentNode *now,
             char name[], int age, char sex, float gpa);
void GoBack(struct studentNode **now);
void DelNode(struct studentNode *now);
void ShowAll(struct studentNode *walk);

/* ===== helper ===== */
static struct studentNode *createNode(char name[], int age, char sex, float gpa)
{
    struct studentNode *n = malloc(sizeof(struct studentNode));
    if (!n) exit(1);

    strcpy(n->name, name);
    n->age = age;
    n->sex = sex;
    n->gpa = gpa;
    n->next = NULL;
    n->back = NULL;

    return n;
}

/* ---------------- MAIN ---------------- */
int main()
{
    struct studentNode *start = NULL;
    struct studentNode *now;

    now = AddNode(&start, "one", 6, 'M', 3.11);
    ShowAll(start);

    now = AddNode(&start, "two", 8, 'F', 3.22);
    ShowAll(start);

    InsNode(now, "three", 10, 'M', 3.33);
    ShowAll(start);

    InsNode(now, "four", 12, 'F', 3.44);
    ShowAll(start);

    GoBack(&now);

    DelNode(now);
    ShowAll(start);

    DelNode(now);
    ShowAll(start);

    DelNode(now);
    ShowAll(start);

    return 0;
}

/* ---------------- FUNCTIONS ---------------- */

/* add node to tail */
struct studentNode *AddNode(struct studentNode **start,
                            char name[], int age, char sex, float gpa)
{
    struct studentNode *node = createNode(name, age, sex, gpa);

    if (*start == NULL)
    {
        *start = node;
        return node;
    }

    struct studentNode *tail = *start;
    while (tail->next)
        tail = tail->next;

    tail->next = node;
    node->back = tail;

    return node;
}

/* insert before current */
void InsNode(struct studentNode *now,
             char name[], int age, char sex, float gpa)
{
    if (!now) return;

    struct studentNode *node = createNode(name, age, sex, gpa);

    node->next = now;
    node->back = now->back;

    if (now->back)
        now->back->next = node;

    now->back = node;
}

/* move current pointer backward */
void GoBack(struct studentNode **now)
{
    if (now && *now && (*now)->back)
        *now = (*now)->back;
}

/* delete current node */
void DelNode(struct studentNode *now)
{
    if (!now) return;

    struct studentNode *L = now->back;
    struct studentNode *R = now->next;

    if (L) L->next = R;
    if (R) R->back = L;

    free(now);
}

/* print list */
void ShowAll(struct studentNode *walk)
{
    while (walk)
    {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}
