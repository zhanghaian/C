#include <stdio.h>
#include <math.h>

int main() {
    unsigned int n;
    scanf("%u", &n);

    if (n % 2 == 1) {
        printf("-1\n");
        return 0;
    }

    int powers[32];
    int count = 0;
    int power = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            powers[count++] = power;
        
        n = n / 2;
        power = power * 2;
    }

    for (int i = count - 1; i >= 0; i--) {
        printf("%d", powers[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");

    return 0;
}
