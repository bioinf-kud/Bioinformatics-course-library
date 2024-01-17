#include <stdio.h>

void vec_add(int *a, int *b, int *c, int n);

int main() {

	int a[] = {1, 2, 3, 4};
	int b[] = {1, 2, 3, 4};
	// 养成随手初始化的好习惯
	int c[4] = {0};
	int n = 4;
	vec_add(a, b, c, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", *(c + i));
	}
	return 0;
}

void vec_add(int *a, int *b, int *c, int n) {
	for (int i = 0; i < n; i++) {
		*(c + i) = *(a + i) + *(b + i);
	}
}