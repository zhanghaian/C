#include <stdio.h>

int mian() {
    long long a[105];
    int count = 0;
    long long temp;

    while (scanf("%lld", &temp) == 1 && temp != 0) {
        a[count] = temp;
        count++;
    }

    for (int i = count - 1; i >= 0; i--) {
        printf("%lld", a[i]);
        if (i > 0) {
            printf(" ");
        }
    }

    return 0;
}