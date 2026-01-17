#include <stdio.h>

int main() {
    int M, N;
    if (scanf("%d %d", &M, &N) != 2) return 0;

    int count[10] = {0};
    for (int i = M; i <= N; i++) {
        int temp = i;

        if (temp == 0) {
            count[0]++;
        }

        while (temp > 0) {
            int a = temp % 10;
            count[a]++;
            temp /= 10;
        }
    }


    for (int i = 0; i < 10; i++) {
        printf("%d ", count[i]);
    }

    printf("\n");
    
    return 0;
}