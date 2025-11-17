#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int original = n;
    int reversed = 0;

    int sum = 0;
    int temp = n;

    while (temp > 0) {
        int digit = temp % 10;
        reversed = reversed * 10 + digit;
        temp /= 10;
    }

    if (reversed == original) {
        temp = n;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }
        printf("%d", sum);
    } else {
        printf("no");
    }

    return 0;
}
