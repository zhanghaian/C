#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* create_list(int n) {
    Node *head = NULL, *tail = NULL;
    for (int i = 1; i <= n; i++) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = i;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }
    return head;
}

void print_list(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        printf("%d%s", curr->data, curr->next ? " -> " : "");
        curr = curr->next;
    }
    printf("\n");
}

Node* reverse_list(Node *head) {
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void free_list(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }
}

int main() {
    int n = 5;
    printf("原始链表: ");
    Node *head = create_list(n);
    print_list(head);

    printf("逆置后的链表: ");
    head = reverse_list(head);
    print_list(head);

    free_list(head);
    return 0;
}