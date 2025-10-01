#include <stdio.h>

int main() {
    float pi = 3.14;
    float r = 0;
    float area = 0;

    scanf("%f", &r);
    area = pi * r * r * r * 4/3;
    printf("%.2f\n", area);

    return 0;
}