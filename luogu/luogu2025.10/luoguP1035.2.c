#include <stdio.h>
#include <math.h>
int main() {
	double k;
	// 使用循环读取输入，直到文件结束或输入错误
	while (scanf("%lf", &k) == 1) {
		// 计算 floor(exp(k - 0.5772156649) + 0.5)
		printf("%.0f\n", floor(exp(k - 0.5772156649) + 0.5));
	}
	return 0;
}


