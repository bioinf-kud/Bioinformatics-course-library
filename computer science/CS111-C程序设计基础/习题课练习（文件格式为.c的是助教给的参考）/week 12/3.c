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