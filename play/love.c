#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

int main() {
    int width = 80;
    int height = 40;
    char canvas[40][80];
    
    // 初始化画布
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            canvas[i][j] = ' ';
        }
    }
    
    printf("\n\n");
    printf("                  参数方程心形 (更精确)\n");
    printf("                  ===================\n\n");
    
    // 使用参数方程绘制心形
    for (double t = 0; t <= 2 * PI; t += 0.01) {
        // 参数方程
        double x = 16 * pow(sin(t), 3);
        double y = 13 * cos(t) - 5 * cos(2*t) - 2 * cos(3*t) - cos(4*t);
        
        // 缩放和平移到屏幕坐标
        int screen_x = (int)(x * 1.5 + width/2);
        int screen_y = (int)(-y * 0.8 + height/2);
        
        // 检查边界
        if (screen_x >= 0 && screen_x < width && screen_y >= 0 && screen_y < height) {
            canvas[screen_y][screen_x] = '*';
        }
    }
    
    // 输出画布
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    printf("                  x = 16sin³(t)\n");
    printf("                  y = 13cos(t) - 5cos(2t) - 2cos(3t) - cos(4t)\n");
    printf("\n");
    
    return 0;
}
