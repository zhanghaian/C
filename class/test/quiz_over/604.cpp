#include <stdio.h>


double calculateTax(double salary, double taxFree) {
    double taxable = salary - taxFree; 
    double tax = 0;

    if (taxable <= 0) {
        tax = taxable * 0.10; //超出额以下不收税，此行改为tax = 0;
    } else if (taxable <= 5000) {
        tax = taxable * 0.05; //5000以下应交10%，此行改为tax = taxable * 0.1
    } else if (taxable > 10000) { 
        tax = 5000 * 0.10 + 5000 * 0.15 + (taxable - 10000) * 0.20; //税率有误，0.20改为0.25
    } else {
        tax = 5000 * 0.10 + (taxable - 5000) * 0.15;
    }

    return salary - tax; 
}

int main() {
    double salary, taxFree;
    printf("请输入工资和免税额度：");
    scanf("%lf %lf", &salary, &taxFree);

    double netSalary = calculateTax(salary, taxFree);
    printf("税后工资是：%.2f\n", netSalary);  

    return 0;
}
