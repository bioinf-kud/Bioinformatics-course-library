#include <stdio.h>

int main() {
	char a[5][100] = {"Hi", "Hello", "Welcome", "Nice", "Bye"}; // ʹ��һ����ά�ַ��������洢��ݶ��ÿһ�д���һ���ַ�����

	int n = 0;
	while (n != -1) {
		printf("����������:");
		scanf("%d", &n);
		if (n == -1)
			break;
		if (n >= 1 && n <= 5) {
			printf("%s\n", a[n - 1]);
		} else {
			printf("����������\n");
		}
	}
	return 0;
}