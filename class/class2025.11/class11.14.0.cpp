#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;

    int isEvenX = (x % 2 == 0);
    int isEvenY = (y % 2 == 0);

    if (isEvenX != isEvenY) {
        return isEvenY - isEvenX;
    }

    return y - x;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), cmp);

    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", arr[i]);
    }

    return 0;
}
