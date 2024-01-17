#include <stdio.h>
#include <string.h>

bool is_palindrome(char *a);

int main() {
	char a[] = "abcde";
	if (is_palindrome(a))
		printf("Yes");
	else
		printf("No");

	printf("\n");
	char b[] = "abcba";
	if (is_palindrome(b))
		printf("Yes");
	else
		printf("No");
	return 0;
}

// bool�ͷ���true����false����1����0���൱��int
bool is_palindrome(char *str) {
//	��������ָ��һ��ָ��ͷһ��ָ���β
	char *begin, *end;
	bool flag = true;

	int len = strlen(str);

//	ǰ������ָ��ͬʱ���м�����ֱ������ָ������
	for (begin = str, end = str + len - 1; begin <= end; begin++, end--) {
//		�����ĳһλ����ȣ�˵�����ǻ��ģ���ֱ���˳�ѭ������false��
		if (*begin != *end) {
			flag = false;
			break;
		}
	}
//	���ѭ������������flagֵû�иı䣬����true

	return flag;
}