#include <stdio.h>
#include <string.h>

int is_palindrome(char *s);

int main() {
	FILE *fptr;
	fptr = fopen("strs.txt", "r");
	char str[20];
	fgets(str, 20, fptr);
	fclose(fptr);

	if (str[strlen(str) - 1] == '\n')
		str[strlen(str) - 1] = '\0';
	int flag = is_palindrome(str);
	fptr = fopen("is_palindrome.txt", "w");

	if (flag == 1)
		fputs("yes", fptr);
	else
		fputs("no", fptr);
	fclose(fptr);

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