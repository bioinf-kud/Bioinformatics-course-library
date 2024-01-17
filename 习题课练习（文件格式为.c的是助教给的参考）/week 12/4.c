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
	//��ȡ�ַ����ĳ���
	int len = strlen(s);
	//��������ָ�룬�ֱ�ָ���ַ�������β
	char *left = s;
	char *right = s + len - 1;
	//ѭ�������ַ������Ƚ���β�ַ��Ƿ����
	while (left < right) {
		//�������ȣ�����false
		if (*left != *right) {
			return 0;
		}
		//���򣬽���ָ�������ƶ�һλ����ָ�������ƶ�һλ
		left++;
		right--;
	}
	//ѭ��������˵���ַ����ǻ��Ĵ�������true
	return 1;
}