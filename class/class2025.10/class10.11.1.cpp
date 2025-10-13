#include <stdio.h>

int main() {
    long long x = 0;
    long long A = 0;
    long long salary = 0;
    if (scanf("%lld", &x) != 1 || x < 0) {
        printf("Invalid input\n");
        return 1;
    }

    if (x >= 3500) {
        A = x - 3500;
        if (A >= 35000) {
            A = 7745 + (A - 35000) * 0.3;
        } else if (A >= 9000) {
            A = 1245 + (A - 9000) * 0.25;
        } else if (A >= 4500) {
            A = 345 + (A - 4500) * 0.2;
        } else if (A >= 1500) {
            A = 45 + (A - 1500) * 0.1;
        } else {
            A = A * 0.03;
        }
    }

    salary = x - A;
    printf("%lld\n", salary);
    return 0;
}