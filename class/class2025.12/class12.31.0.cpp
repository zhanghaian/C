#include <stdio.h>

struct Data {
    int year;
    int mouth;
    int day; 
};

int main() {
    struct Data d;
    if (scanf("%d,%d,%d", &d.year, &d.mouth, &d.day) != 3) {
        return 0;
    }

    int mouth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((d.year % 4 == 0) && (d.year % 100 != 0) || (d.year % 400 == 0)) {
        mouth[2] = 29;
    }

    int totalDays = 0;

    for (int i = 0; i < d.mouth; i++) {
        totalDays += mouth[i];
    }
    totalDays += d.day;

    printf("%d\n", totalDays);

    return 0;
}