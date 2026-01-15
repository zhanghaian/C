#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int a[105];
    for (int i = 0; i , n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                count++;
            }
        }
        printf("%d ", count);
    }

    printf("\n");
    return 0;
}