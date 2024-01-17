#include <stdio.h>

int main() {
	double a[3][5];
//	读入二维数组
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%lf", &a[i][j]);
		}
	}

// 计算每组五个值的平均值
	double sum = 0;
	for (int i = 0; i < 3; i++) {
		sum = 0;
		for (int j = 0; j < 5; j++) {
			sum += a[i][j];
		}
		printf("每组平均值=%lf\n", sum / 5);
	}

//	计算所有值的平均值
	sum = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			sum += a[i][j];
		}
	}
	printf("总平均值=%lf\n", sum / 15);

// 计算最大值
	double max = a[0][0];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			if (a[i][j] > max)
				max = a[i][j];
		}
	}
	printf("最大值=%lf\n", max);
}