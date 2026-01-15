#include <stdio.h>

int main() {
    double s, x;
    if (scanf("%lf %lf", &s, &x) != 2) return 0;

    double current_pos = 0;
    double step = 7;
    double left = s - x;
    double right = s + x;

    while (current_pos < left) {
        current_pos += step;
        step *= 0.98;
    }

    if (current_pos + step > right) {
        printf("n\n");
    } else {
        printf("y\n");
    }

    return 0;
}