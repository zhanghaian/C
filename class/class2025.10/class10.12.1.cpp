#include <stdio.h>

int main() {
    int m, s;
    scanf("%d %d", &m, &s);
    double t = m + (double)s / 60.0;  
    double c;
    if (t <= 10.0) {
        c = 100.0 - 5.0 * t;
    } else if (t <= 30.0) {
        c = 50.0 - (t - 10.0);
    } else if (t <= 50.0) {
        c = 30.0 - (t - 30.0) / 2.0;
    } else {
        c = 20.0;
    }
    printf("%.1f\n", c);
    return 0;
}