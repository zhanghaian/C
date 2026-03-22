#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int a[1000] = {0};
    int count = 0;
    int num = 0;
    int i = 0;

    while (num < n - 1) {
        if (a[i] == 0) {
            count++;
            if (count == m) {
                a[i] = 1;
                printf("%d ", i + 1);
                count = 0;
                num++;
            }
        }
        i = (i + 1) % n;
    }

    for (i = 0; i < n; i++) {
        if (a[i] == 0) {
            printf("\nLast: %d\n", i + 1);
        }
    }

    return 0;
}