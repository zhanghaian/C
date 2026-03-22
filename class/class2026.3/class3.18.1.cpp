#include <stdio.h>
#include <stdlib.h>

#define kMaxSize 20
typedef int ElemSet;
typedef int Position; /* 整型下标，表示元素的位置 */
typedef struct ListNode *List;
struct ListNode {
    ElemSet data[kMaxSize]; /* 存储数据的数组 */
    Position last; /* 线性表中最后一个元素在数组中的位置 */
};

List Delete( List list, ElemSet min_value, ElemSet max_value );

int main(void)
{
    List list;
    ElemSet min_value, max_value;
    int i;

    list = (List)malloc(sizeof(struct ListNode));
    scanf("%d", &list->last);
    for (i=0; i<=list->last; i++){
        scanf("%d", &list->data[i]);
    }
    scanf("%d %d", &min_value, &max_value);
    list = Delete(list, min_value, max_value);
    for (i=0; i<=list->last; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");

    return 0;
}

List Delete( List list, ElemSet min_value, ElemSet max_value ) {
    int i, j = 0;
    
    for (i = 0; i <= list->last; i++) {
        if (!list->data[i] > min_value && list->data[i] < max_value) {
            list->data[j++] = list->data[i];
        }
    }

    list->last =  j - 1;

    return list;
}