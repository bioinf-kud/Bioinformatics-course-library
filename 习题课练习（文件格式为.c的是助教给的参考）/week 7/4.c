#include <stdio.h>

int main() {
	char a[5][100] = {"Hi", "Hello", "Welcome", "Nice", "Bye"}; // 使用一个二维字符数组来存储快捷短语，每一行代表一个字符串。

	int n = 0;
	while (n != -1) {
		printf("请输入数字:");
		scanf("%d", &n);
		if (n == -1)
			break;
		if (n >= 1 && n <= 5) {
			printf("%s\n", a[n - 1]);
		} else {
			printf("请重新输入\n");
		}
	}
	return 0;
}