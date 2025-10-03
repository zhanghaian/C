#include <stdio.h>

int main(){
    int pass = 0;
    int score = 0;
    printf("请输入你的成绩：");
    scanf("%d", &score);
    if (score >= 60){
        printf("恭喜你，及格了\n");
    }
    else {
        printf("很抱歉，你没有及格\n");

    }
    printf("再见\n");
    return 0;
}