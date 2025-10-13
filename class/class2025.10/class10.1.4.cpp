#include <stdio.h>

int main() {
    int f = 0;
    double c = 0;

    scanf("%d", &f);
    c = ( f - 32 ) * 5 / 9.0;
    printf("%.2f\n", c);

    return 0;
}