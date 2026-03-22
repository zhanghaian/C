#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct LNode{
	int  data;			//数据域
	struct  LNode  *next;	//指针域
}LNode, *LinkList;

LinkList createList();
void outputList(LinkList);
void reverseList(LinkList);

int main(){ 
  	LinkList head = createList();
	outputList(head);
	reverseList(head);
	outputList(head);
	return 0;	 
}

LinkList createList() {
	
	LinkList head, r, p;
	int val;
     //空表（仅有头结点）
    head = (LNode *)malloc(sizeof(LNode));
    head->next  = NULL;
    r = head;

    while (1) {
    	 scanf("%d", &val);
    	 if (val==0) break;
    	 
         p = (LNode *)malloc(sizeof(LNode));
         if (!p) break;       
		 p->data = val;
		 p->next = r->next;  
         r->next = p;
         r = p;
    }

    return head; 	
}

void outputList(LinkList head) {
	LinkList p = head;
	if (!p ||!(p->next)) {
		printf("Empty List\n"); 
		return;
	}
	p = head->next;
	printf("%d", p->data);
	p = p->next;
	while (p) {
		printf(" %d", p->data);
		p = p->next;
	}
	printf("\n");
}

