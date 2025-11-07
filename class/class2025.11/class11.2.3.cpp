#include <stdio.h>

int main() {
    int M;
    scanf("%d", &M);

    int count = 0;

    for (int a = 1; a <= 9; a++) {
        for (int b = 0; b <= 9; b++) {
            for (int c = 0; c <= 9; c++) {
                int num = 10001 * a + 1010 * b + 100 * c; // 构造五位回文数
                if (num % M == 0) {
                    count++;
                }
            }
        }
    }

    printf("%d %d\n", M, count);
    return 0;
}
