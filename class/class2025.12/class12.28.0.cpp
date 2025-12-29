#include <stdio.h>

int isPrime(int n) {
    if (n < 2 ) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int getNthPrime(int n) {
    int count = 0, num = 2;
    while (count < n) {
        if (isPrime(num)) count++;
        if (count < n) num++;
    }
    return num;
}

int main() {
    int p, sum = 0;
    scanf("%d", &p);

    int start = getNthPrime(p);
    for (int i = 0; i < 11; i++) {
        sum += start; 
        start = getNthPrime(p + i + 1);
    }

    printf("%d\n", sum);
    return 0;

}