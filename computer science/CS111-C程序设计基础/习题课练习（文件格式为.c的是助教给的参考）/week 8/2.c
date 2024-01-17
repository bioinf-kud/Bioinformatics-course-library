#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char input[100];
	char output[100];
	printf("Enter the sentence: ");
	gets(input);

	// 让下标i停留在第一个不是空格的字符上
	int i = 0;
	for (i = 0; i < strlen(input); i++) {
		if (input[i] != ' ')
			break;
	}

	// 从下标i开始给数组output赋值
	for (int j = 0;; j++, i++) {
		output[j] = input[i];
		// 如果当前字符接下来的两个字符都是空格，就判断字符串结束
		if (input[i + 1] == ' ' && input[i + 2] == ' ') {
			output[j + 1] = '\0';
			break;
		}
	}

	printf("The new sentence: %s", output);
	return 0;
}