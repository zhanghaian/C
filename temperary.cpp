#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int a[1000] = {0}; // 0表示未出列，1表示已出列
    int count = 0;     // 当前报数
    int num = 0;       // 已出列人数
    int i = 0;         // 当前下标

    while (num < n - 1) {
        if (a[i] == 0) { // 没出列才报数
            count++;
            if (count == m) {
                a[i] = 1; // 出列
                printf("%d ", i + 1);
                count = 0;
                num++;
            }
        }
        i = (i + 1) % n; // 循环
    }

    // 找最后一个人
    for (i = 0; i < n; i++) {
        if (a[i] == 0) {
            printf("\nLast: %d\n", i + 1);
        }
    }

    return 0;
}