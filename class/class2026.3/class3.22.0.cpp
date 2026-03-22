#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* create_circle(int n) {
    Node *head = NULL, *prev = NULL;
    for (int i = 1; i <= n; i++) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = i;
        if (head == NULL) {
            head = newNode;
        } else {
            prev->next = newNode;
        }
        prev = newNode;
    }
    prev->next = head;
    return head;
}

void josephus(int n, int m) {
    Node *head = create_circle(n);
    Node *curr = head;
    Node *prev = NULL;

    printf("出圈顺序: ");
    while (curr->next != curr) {
        for (int i = 1; i < m; i++) {
            prev = curr;
            curr = curr->next;
        }
        printf("%d ", curr->data);
        prev->next = curr->next;
        free(curr);
        curr = prev->next;
    }
    printf("\n最后剩下的人是: %d\n", curr->data);
    free(curr);
}

int main() {
    int n, m;
    printf("请输入总人数 n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("输入错误，请输入正整数。\n");
        return 1;
    }
    printf("请输入报数间隔 m: ");
    if (scanf("%d", &m) != 1 || m <= 0) {
        printf("输入错误，请输入正整数。\n");
        return 1;
    }

    josephus(n, m);

    return 0;
}