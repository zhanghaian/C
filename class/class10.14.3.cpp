#include <stdio.h>

int isSkip(int x) {
    if (x % 7 == 0) return 1;
    while (x > 0) {
        if (x % 10 == 7) return 1;
        x /= 10;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int skip[3] = {0, 0, 0};
    int count = 0;
    int num = 0;
    int player = 0;
    while (count < n) {
        num++;
        if (isSkip(num)) {
            skip[player]++;
        } else {
            count++;
        }

        player = (player + 1) % 3;
    }

    printf("%d %d %d\n", skip[0], skip[1], skip[2]);
    return 0;
}
