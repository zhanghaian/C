#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct LNode{
	int  data;
	struct  LNode  *next;
}LNode, *LinkList;

LinkList createList();
void outputList(LinkList);
void reverseList(LinkList);

int main(){ 
  	LinkList head = createList();
	reverseList(head);
	outputList(head);
	return 0;	 
}

LinkList createList() {
	LinkList head, r, p;
	int val;
    head = (LNode *)malloc(sizeof(LNode));
    head->next  = NULL;
    r = head;

    while (1) {
    	 if (scanf("%d", &val) != 1 || val == 0) break;
    	 
         p = (LNode *)malloc(sizeof(LNode));
         if (!p) break;       
		 p->data = val;
		 p->next = NULL;  
         r->next = p;
         r = p;
    }

    return head; 	
}

void outputList(LinkList head) {
	if (!head || !(head->next)) {
		return;
	}
	LinkList p = head->next;
	while (p) {
		printf("%d", p->data);
		if (p->next) printf(" ");
		p = p->next;
	}
	printf("\n");
}

void reverseList(LinkList head) {
    if (!head || !head->next || !head->next->next) {
        return;
    }
    
    LinkList prev = NULL;
    LinkList curr = head->next;
    LinkList next = NULL;
    
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    head->next = prev;
}