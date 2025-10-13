#include <stdio.h>

int main() {
    float T = 0;
    float t = 0;
    int h = 0;
    int m = 0;

    scanf("%d %d", &h, &m);
    t = h + m / 60.0;
    T = ( 4 * t * t)/(t + 2) - 20;
    printf("%.2f\n", T);

    return 0;
}