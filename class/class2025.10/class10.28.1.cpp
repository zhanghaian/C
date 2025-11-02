#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int max_len = 1; 
    int count = 1;

    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            count++;
        } else {
            if (count > max_len)
                max_len = count;
            count = 1;
        }
    }

    if (count > max_len)
        max_len = count;

    printf("%d\n", max_len);

    return 0;
}
