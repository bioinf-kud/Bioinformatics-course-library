#include <stdio.h>

int main() {
	double a[3][5];
//	�����ά����
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%lf", &a[i][j]);
		}
	}

// ����ÿ�����ֵ��ƽ��ֵ
	double sum = 0;
	for (int i = 0; i < 3; i++) {
		sum = 0;
		for (int j = 0; j < 5; j++) {
			sum += a[i][j];
		}
		printf("ÿ��ƽ��ֵ=%lf\n", sum / 5);
	}

//	��������ֵ��ƽ��ֵ
	sum = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			sum += a[i][j];
		}
	}
	printf("��ƽ��ֵ=%lf\n", sum / 15);

// �������ֵ
	double max = a[0][0];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			if (a[i][j] > max)
				max = a[i][j];
		}
	}
	printf("���ֵ=%lf\n", max);
}