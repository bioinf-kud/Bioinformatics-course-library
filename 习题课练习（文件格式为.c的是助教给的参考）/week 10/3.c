#include <stdio.h>

void fun(int *a, int n, int *odd, int *even);

int main() {
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int n = 8;
//	����һ��Ҫ����������ͬ�ı�������ָ��ͬ�ĵ�ַ
	int odd = 0;
	int even = 0;
	fun(a, n, &odd, &even);
	printf("����֮��Ϊ%d��ż��֮��Ϊ%d", odd, even);
	return 0;

}

void fun(int *a, int n, int *odd, int *even) {
//	��ʼ��
	*odd = 0;
	*even = 0;

	for (int i = 0; i < n; i++) {
//		*(a+i)�ȼ���a[i]
		if (*(a + i) % 2 == 1)
			*odd += *(a + i);
		else
			*even += *(a + i);
	}
}