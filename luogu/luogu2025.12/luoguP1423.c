#include <stdio.h>

int main() {
    float s;
    scanf("%f", &s);

    float length = 0.0;
    float step = 2.0;
    int cnt = 0;
    while (length < s) {
        length += step;
        step *= 0.98;
        cnt++;
    }

    printf("%d\n", cnt);
    return 0;
}