#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrome(char *s);

int main() {
	FILE *fptr_in;
	FILE *fptr_out;

	fptr_in = fopen("strs.txt", "r");

	char str[20];
	fgets(str, 20, fptr_in);
	int n = atoi(str);
//	printf("%d", n);

	fptr_out = fopen("is_palindrome.txt", "w");
	for (int i = 0; i < n; i++) {
		fgets(str, 20, fptr_in);
		if (str[strlen(str) - 1] == '\n')
			str[strlen(str) - 1] = '\0';
//		printf("%s ", str);
		int flag = is_palindrome(str);
//		printf("%d\n", flag);
		if (flag == 1)
			fputs("yes\n", fptr_out);
		else
			fputs("no\n", fptr_out);
	}

	fclose(fptr_in);
	fclose(fptr_out);

	return 0;
}

int is_palindrome(char *s) {
	//获取字符串的长度
	int len = strlen(s);
	//定义两个指针，分别指向字符串的首尾
	char *left = s;
	char *right = s + len - 1;
	//循环遍历字符串，比较首尾字符是否相等
	while (left < right) {
		//如果不相等，返回false
		if (*left != *right) {
			return 0;
		}
		//否则，将左指针向右移动一位，右指针向左移动一位
		left++;
		right--;
	}
	//循环结束后，说明字符串是回文串，返回true
	return 1;
}