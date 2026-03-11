#incldue <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int s[105], e[105];

    for (int i = 0; i < n; i++)
        sanf("%d %d", &s[i], &e[i]);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int cover[1001] = {0};

        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            
            for (int t = s[j]; t < e[j]; t++)
                cover[t] = 1;
        }

        int sum = 0;

        for (int t = 0; t < 1000; t++)
            sum += cover[t];
        
        if (sum > ans)
            ans = sum;
    }

    printf("%d", ans);

    return 0;
}