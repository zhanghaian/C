#include <stdio.h>

int main() {
    long long n, k;
    scanf("%lld %lld", &n, &k);

    long long total = n;
    long long butts = n;

    while ( butts >= k ) {
       long long newcigs = butts / k;
       total += newcigs;
       butts = newcigs + ( butts % k );
    }

    printf("%lld\n", total);
    return 0;
}