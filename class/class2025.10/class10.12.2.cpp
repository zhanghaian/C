#include <stdio.h>

int main() {
    double kwh;
    scanf("%lf", &kwh);
    double fee = 0.0;
    if (kwh <= 110.0) {
        fee = kwh * 0.5;
    } else {
        fee += 110.0 * 0.5; 
        double second = (kwh > 210.0) ? 100.0 : (kwh - 110.0);
        fee += second * 0.55; 
        if (kwh > 210.0) {
            fee += (kwh - 210.0) * 0.70; 
        }
    }
    printf("%.2f\n", fee);
    return 0;
}