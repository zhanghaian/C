#include <stdio.h>

int a[1000005];

int main() {
    int n, cur_len = 1, max_len = 1;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i < n; i++) {
        if (a[i] > a[i-1]) {
            cur_len++;
        } else {
            if (cur_len > max_len) max_len = cur_len;
            cur_len = 1;
        }
    }

    if (cur_len > max_len) max_len = cur_len;

    printf("%d\n", max_len);
    return 0;
}