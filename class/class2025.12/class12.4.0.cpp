#include <stdio.h>

int main() {
    int n, x;
    scanf("%d", &n);

    int stack[10000];
    int top = -1;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (top >= 0 && stack[top] == x) {
            top--;
        } else {
            stack[++top] = x;
        }
    }

    if (top == -1) {
        printf("NULL");
    } else {
        for (int i = 0; i <= top; i++) {
            if (i) printf(" ");
            printf("%d", stack[i]);
        }
    }
    
    printf("\n");

    return 0;
}