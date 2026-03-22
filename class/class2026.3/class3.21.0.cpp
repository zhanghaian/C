#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
//定义
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node, *LinkList;

void InitList(LinkList *L) {
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
}

//插入元素
int Insert(LinkList L, int i, ElemType e) {
    Node *p = L;
    int j = 0;

    while (p && j < i - 1) {
        p = p->next;
        j++;
    }

    if (!p || j > i - 1) return 0;

    Node *s = (Node *)malloc(sizeof(Node));
    s->data = e;

    s->next = p->next;
    p->next = s;

    return 1;
}

//删除元素
int Delete(LinkList L, int i) {
    Node *p = L;
    int j = 0;

    while (p->next && j < i - 1) {
        p = p->next;
        j++;
    }

    if (!(p->next) || j > i - 1) return 0;

    Node *q = p->next;
    p->next = q->next;
    free(q);

    return 1;
}

//遍历输出
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

int main() {
    LinkList L;
    InitList(&L);

    int x;

    while (scanf("%d", &x) && x != 0) {
        Insert(L, 1, x);
    }

    Traverse(L);

    while (L->next) {
        Delete(L, 1);
        Traverse(L);
    }

    return 0;
}