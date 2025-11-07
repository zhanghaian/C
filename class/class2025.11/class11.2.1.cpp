#include <stdio.h>

int sum_of_proper_divisors(int x, int *count) {
    int sum = 1;  
    *count = 1; 
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            sum += i;
            (*count)++;
            if (i != x / i) {
                sum += x / i;
                (*count)++;
            }
        }
    }
    return sum;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int a = n; a <= m; a++) {
        int countA;
        int b = sum_of_proper_divisors(a, &countA);

        if (b > a && b <= m) {  // 防止重复
            int countB;
            int sumB = sum_of_proper_divisors(b, &countB);
            if (sumB == a) {
                printf("%d %d,%d %d\n", a, countA, b, countB);
            }
        }
    }

    return 0;
}
