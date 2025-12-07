#include <stdio.h>
#include <string.h>

int main () {

    char a[1005], b[1005], res[1005];
    scanf("%s %s", a, b);

    int i = strlen(a) - 1;
    //的到a字符串的最后一个索引，就是用strlen来算出来长度再-1，减去最后的那个\0;
    int j = strlen(b) - 1;
    int k = 0, carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int x = (i >= 0 ? a[i--] - '0' : 0);
        int y = (j >= 0 ? b[j--] - '0' : 0);
        int sum = x + y + carry;
        
        res[k++] = sum % 10 + '0';
        carry = sum / 10;
    }

    for (int t = k - 1; t >= 0; t--)
        putchar(res[t]);
    putchar('\n');

    return 0;
}