#include <stdio.h>

int search(int key, int a[], int length);

int main(void) {
    int a[] = {2,4,6,7,1,3,5,9,11,13,23,14,32};
    //数组的集成初始化
    //test
    //水平制表\t
    {
        int i;
        for ( i = 0; i < 13; i++ ) {
            printf("%d\t", a[i]);
        }
        printf("\n");
    }
    //sizeof(a)/sizeof(a[0])更加安全的到有多少个元素一旦修改初始的数量更方便
    {
        int b[10] = { [0] = 1, [2] = 3, 4 };
        for ( int i = 0; i < 10; i++ ) {
            printf("%d\t", b[i]);
        }
    }
    int x;
    int loc;
    printf("请输入一个数字：");
    scanf("%d", &x);
    loc = search(x, a, sizeof(a)/sizeof(a[0]));
    if ( loc != 1 ) {
        printf("%d在第%d个位置上\n", x, loc);
    } else {
        printf("%d不存在", x);
    }

    return 0;
}

int search(int key, int a[], int length)
{
    int ret = -1;
    int i;
    for ( i = 0; i < length; i++ ) {
        if (a[i] == key ) {
            ret = i;
            break;
        }
    }

    return ret;
}