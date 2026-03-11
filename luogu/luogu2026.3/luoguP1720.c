#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    double f[50];

    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++)
        f[i] = f[i-1] + f[i-2];
    
    printf("%.2f", f[n]);

    return 0;
}