#include <stdio.h>

int main() {
    int n, i, j, flag = 0;
    int min_val = 10001, max_val = -10001;

    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < min_val) min_val = a[i];
        if (a[i] > max_val) max_val = a[i];
    }

    for (i = 0; i < n; ) {
        j = i;
        while (j + 1 < n && a[j] < a[j+1]) {
            j++;
        }

        if (j > i) {
            printf("%d %d\n", i, j);
            flag = 1;
            i = j + 1;
        } else {
            i++;
        }
    }

    if (!flag) {
        printf("%d %d\n", min_val, max_val);
    }

    return 0;
}