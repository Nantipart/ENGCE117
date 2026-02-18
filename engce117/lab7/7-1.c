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

/* ===== LinkedList ===== */
typedef struct {
    struct studentNode *start;
    struct studentNode *now;
} LinkedList;

/* ===== NewList (ใช้ logic พิเศษ) ===== */
typedef LinkedList NewList;

/* ===== create node ===== */
struct studentNode* createNode(char n[], int a, char s, float g) {
    struct studentNode *p = malloc(sizeof(struct studentNode));
    strcpy(p->name, n);
    p->age = a;
    p->sex = s;
    p->gpa = g;
    p->next = NULL;
    return p;
}

/* ===== Insert End ===== */
void InsNode(LinkedList *L, char n[], int a, char s, float g) {

    struct studentNode *node = createNode(n,a,s,g);

    if(L->start == NULL){
        L->start = node;
        L->now = node;
        return;
    }

    struct studentNode *t = L->start;
    while(t->next) t = t->next;

    t->next = node;
    L->now = node;
}

/* ===== Delete Now ===== */
void DelNode(LinkedList *L) {

    if(L->now == NULL) return;

    if(L->now == L->start){
        L->start = L->start->next;
        free(L->now);
        L->now = L->start;
        return;
    }

    struct studentNode *t = L->start;
    while(t->next != L->now) t = t->next;

    t->next = L->now->next;
    free(L->now);
    L->now = t->next;
}

/* ===== Move Next ===== */
void GoNext(LinkedList *L){
    if(L->now && L->now->next)
        L->now = L->now->next;
}

/* ===== Show current ===== */
void ShowNode(LinkedList *L){
    if(L->now)
        printf("%s %d %c %.2f\n",
               L->now->name,
               L->now->age,
               L->now->sex,
               L->now->gpa);
}

/* ===== Show last 2 nodes (NewList style) ===== */
void ShowNodeNew(NewList *L){

    struct studentNode *t = L->start;
    struct studentNode *last = NULL;
    struct studentNode *before = NULL;

    while(t){
        before = last;
        last = t;
        t = t->next;
    }

    if(before) printf("%s ", before->name);
    if(last) printf("%s", last->name);
    printf("\n");
}

/* ================= MAIN ================= */
int main(){

    LinkedList listA = {NULL,NULL};
    NewList listB = {NULL,NULL};
    LinkedList *listC;

    /* listA */
    InsNode(&listA,"one",1,'A',1.10);
    InsNode(&listA,"two",2,'B',2.20);
    InsNode(&listA,"three",3,'C',3.30);

    GoNext(&listA);
    ShowNode(&listA);   // two 2 B 2.20

    /* listB */
    InsNode(&listB,"four",4,'D',4.40);
    InsNode(&listB,"five",5,'E',5.50);
    InsNode(&listB,"six",6,'F',6.60);

    GoNext(&listB);
    DelNode(&listB);

    ShowNodeNew(&listB); // six four

    /* listC */
    listC = &listA;
    GoNext(listC);
    ShowNode(listC);     // one 1 A 1.10

    ShowNodeNew(&listB); // six four

    return 0;
}
