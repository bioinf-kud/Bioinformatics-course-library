#include <stdio.h>

void fun(int *a, int n, int *odd, int *even);

int main() {
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int n = 8;
//	这里一定要定义两个不同的变量让其指向不同的地址
	int odd = 0;
	int even = 0;
	fun(a, n, &odd, &even);
	printf("奇数之和为%d，偶数之和为%d", odd, even);
	return 0;

}

void fun(int *a, int n, int *odd, int *even) {
//	初始化
	*odd = 0;
	*even = 0;

	for (int i = 0; i < n; i++) {
//		*(a+i)等价于a[i]
		if (*(a + i) % 2 == 1)
			*odd += *(a + i);
		else
			*even += *(a + i);
	}
}