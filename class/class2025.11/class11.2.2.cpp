#include <stdio.h>
#include <math.h>

int isPrime(int x) {
    if (x < 2) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main() {
    int p;
    scanf("%d", &p);

    int count = 0;
    int num = 2;
    int primes[200]; // 足够存放前150+10个质数
    while (count < p + 10) {
        if (isPrime(num)) {
            primes[++count] = num;
        }
        num++;
    }

    int sum = 0;
    for (int i = p; i <= p + 10; i++) {
        sum += primes[i];
    }

    printf("%d\n", sum);
    return 0;
}
