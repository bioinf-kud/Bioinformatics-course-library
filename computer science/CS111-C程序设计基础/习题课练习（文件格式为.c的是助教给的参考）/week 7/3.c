#include <stdio.h>

int main() {
	char a[100];
	char b[100];
	printf("Enter first word: ");
	gets(a);
	printf("Enter second word: ");
	gets(b);

	int num[26]; // ���ڴ��26����ĸ���ֵĴ���
	for (int i = 0; i < 26; i++) {
		num[i] = 0;
	}

	for (int i = 0; i < 100; i++) {
		if (a[i] == '\0') // ����ж϶������ַ���ĩβ����'\0'������ֹ����
			break;
		num[a[i] - 'a'] ++; // ���a[0]Ϊ�ַ�'a'����a[i]-'a'�Ľ��Ϊ0������num[0]��+1
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