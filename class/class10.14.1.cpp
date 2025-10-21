#include <stdio.h>

int main() {
    int n;
    scanf("%d\n", &n);
    int t;
    scanf("%d", &t);

    int change[20];
    for (int i = 0; i < n; i++) {
        scanf("%d", &change[i]);
    }

    int maxDrop = 0;
    int maxRound = 0;
    int total = t;

    for (int i = 0; i < n; i++) {
        total += change[i];  
        if (change[i] < 0) { 
            int drop = -change[i]; 
            if (drop > maxDrop) {
                maxDrop = drop;
                maxRound = i + 1;  
            }
        }
    }

    printf("%d %d\n", total, maxRound);
    return 0;
}
