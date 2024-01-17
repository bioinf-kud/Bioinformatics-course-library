#include <stdio.h>

int main() {
	char a[100];
	char b[100];
	printf("Enter first word: ");
	gets(a);
	printf("Enter second word: ");
	gets(b);

	int num[26]; // 用于存放26个字母出现的次数
	for (int i = 0; i < 26; i++) {
		num[i] = 0;
	}

	for (int i = 0; i < 100; i++) {
		if (a[i] == '\0') // 如果判断读到了字符串末尾，即'\0'，就终止计数
			break;
		num[a[i] - 'a'] ++; // 如果a[0]为字符'a'，则a[i]-'a'的结果为0，即在num[0]处+1
	}

	for (int i = 0; i < 100; i++) {
		if (a[i] == '\0')
			break;
		num[b[i] - 'a'] --;
	}

	for (int i = 0; i < 26; i++) {
		if (num[i] != 0) {
			printf("The words are not anagrams.");
			return 0;
		}
	}
	printf("The words are anagrams.");
	return 0;
}