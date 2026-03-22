#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
//定义
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node, *LinkList;

//创建
void CreateList(LinkList *L) {
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;

    Node *tail = *L;
    int x;

    while (scanf("%d", &x) && x != 0) {
        Node *p = (Node *)malloc(sizeof(Node));
        p->data = x;
        p->next = NULL;

        tail->next = p;
        tail = p;
    }
}

//遍历
void Traverse(LinkList L) {
    Node *p = L->next;

    if (!p) {
        printf("empty list!\n");
        return;
    }

    while (p) {
        printf("%d", p->data);
        if (p->next) printf(" ");
        p = p->next;
    }
    printf("\n");
}

//冒泡
void BubbleSort(LinkList L) {
    if (!L->next) return;

    int swapped;
    Node *p, *q;
    ElemType temp;

    do {
        swapped = 0;
        p = L->next;

        while (p->next) {
            q = p->next;
            if (p->data > q->data) {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
                swapped = 1;
            }
            p = p->next;
        }
    } while (swapped);
}

int main() {
    LinkList L;
    CreateList(&L);

    Traverse(L);

    BubbleSort(L);

    Traverse(L);

    return 0;
}