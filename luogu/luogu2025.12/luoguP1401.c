#include <stdio.h>
#include <limits.h>

int main() {

    long long xl, xu, yl, yu;
    scanf("%lld %lld", &xl, &xu);
    scanf("%lld %lld", &yl, &yu);

    long long P1 = xl * yl;
    long long P2 = xl * yu;
    long long P3 = xu * yl;
    long long P4 = xu * yu;

    long long minP = P1;
    if (P2 < minP) minP = P2;
    if (P3 < minP) minP = P3;
    if (P4 < minP) minP = P4;

    long long maxP = P1;
    if (P2 < maxP) maxP = P2;
    if (P3 < maxP) maxP = P3;
    if (P4 < maxP) maxP = P4;

    if (minP < INT_MIN || maxP > INT_MAX) {
        printf("long long int\n");
    } else {
        printf("int\n");
    }
    
    return 0;
}