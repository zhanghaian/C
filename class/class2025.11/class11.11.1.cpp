#include <stdio.h>

int main() {
    int y, d;
    scanf("%d %d", &y, &d);

    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) {
        month_days[1] = 29;
    }

    int month = 0;

    while (d > month_days[month]) {
        d -= month_days[month];
        month++;
    }

    printf("%d %d\n", month + 1, d);

    return 0;
}
