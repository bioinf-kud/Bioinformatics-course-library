#include <stdio.h>
#include <string.h>

void strip(char *new_str, char *old_str);

int main() {
	char a[] = "     i have a pen     ";
	char b[100];
	strip(b, a);
	printf("%s", b);
	return 0;
}

void strip(char *new_str, char *old_str) {
//	ָ������ָ�룬һ��ָ���ַ����Ŀ�ͷ��һ��ָ���ַ�����ĩβ
	char *begin = old_str;
	char *end = old_str + strlen(old_str) - 1;

//	�ÿ�ͷָ��ͣ���ڵ�һ���ǿո���ַ���
	while (*begin == ' ')
		begin++;

//	�ý�βָ��ͣ�������һ���ǿո���ַ���
	while (*end == ' ')
		end--;

//  ��beginָ�뿪ʼ���ƣ�����end-begin+1���ַ�
	strncpy(new_str, begin, end - begin + 1);
}