#include <stdio.h>

int main() {
    int N, M;
    if (scanf("%d %d", &N, &M) != 2) return 0;

    long long square_count = 0;
    long long rectangle_count = 0;

    for (int x1 = 1; x1 <= N; x1++) {
        for (int y1 = 1; y1 <= M; y1++) {
            for(int x2 = x1; x2 <= N; x2++) {
                for (int y2 = y1; y2 <= M; y2++) {
                    int len = x2 - x1 + 1;
                    int wid = y2 - y1 + 1;

                    if (len == wid) {
                        square_count++;
                    } else {
                        rectangle_count++;
                    }
                }
            }
        }
    }

    printf("%lld %lld\n", square_count, rectangle_count);

    return 0;
}