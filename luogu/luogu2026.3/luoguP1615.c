#include <stdio.h>

int main() {
    int h1, m1, s1;
    int h2, m2, s2;
    int n;

    scanf("%d:%d:%d", &h1, &m1, &s1);
    scanf("%d:%d:%d", &h2, &m2, &s2);

    scanf("%d", &n);

    int t1 = h1 * 3600 + m1 * 60 + s1;
    int t2 = h2 * 3600 + m2 * 60 + s2;

    int diff = t2 - t1;

    printf("%d", diff * n);

    return 0;
}