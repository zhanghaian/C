


int insertList(LinkList &L, int i, ElemType e);
int deleteList(LinkList &L, int i, ElemType &e);
void ()

int main() {
    LinkList L;
    L = new LNode;


}

int insertList(LinkList &L, int i, ElemType e) {
    int k = 0;
    LNode *p = L;

    while (p && k < i - 1) {
        p = p->next;
        ++k;
    }

    if (!p || i < = 0 ) return 0;
    
    LNode *s = new LNode;
    s->data = e;
}