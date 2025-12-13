#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

int main() {

    int n;
    scanf("%d", &n);

    int a[10005];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    qsort(a, n, sizeof(int), cmp);
    int max_len = 1;
    int cur_len = 1;
    //current

    for(int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            continue;
        } else if (a[i] ==a[i - 1] + 1) {
            cur_len++;
        } else {
            cur_len = 1;
        }

        if (cur_len > max_len) {
            max_len = cur_len;
        }
    }

    printf("%d\n", max_len);

    return 0;
}