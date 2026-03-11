#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

int insertList (LinkList &L, int i, ElemType e);
int deleteList (LinkList &L, int i, ElemType &e);


int main( ) {
    LinkList L;
    L = new LNode;
    L->next = nullptr;

    for (int i = 0; i < 10; ++i) 
        insertList (L, i + 1, (i + 1) * 10);

        LNode *p = L->next;
        while (p) {
            cout << p ->data << " ";
            p = p->next;
        }
        cout << endl;
        
        return 0;
   
}

int insertList(LinkList &L, int i, ElemType e) {
    int k = 0;
    LNode *p = L;

    while (p && k < i - 1) {
        p = p->next;
        ++k;
    }

    if (!p || i <= 0)
        return 0;
    
    LNode *s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;

    return 1;
}