#include <stdio.h>
#include <string.h>

int main() 
{
    int n;
    if(scanf("%d", &n) != 1) return 0;

    getchar();

    char name[10][30];
    double price[10];
    char line[100];

    for(int i = 0; i < n; i++)
    {
    //gets已经被弃用因为会有溢出的问题，scanf("%d", str);不会读取空格，but gets可以读取一行直至\n
    //现在使用fgets(str, sizeof(str), stdin); stdin表示输入来源是标准输入（键盘）
        if(fgets(name[i], 50, stdin) == NULL) return 0;
        name[i][strcspn(name[i], "\n")] = '\0';

        // 读取价格
        if(fgets(line, sizeof(line), stdin) == NULL) return 0;
        sscanf(line, "%lf", &price[i]);
    }

    int max = 0, min = 0;
    for(int i = 1; i < n; i++)
    {
        if(price[i] > price[max]) max = i;
        if(price[i] < price[min]) min = i;
    }

    printf("%.2lf, %s\n", price[max], name[max]);
    printf("%.2lf, %s\n", price[min], name[min]);

    return 0;
}