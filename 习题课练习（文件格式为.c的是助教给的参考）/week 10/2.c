#include <stdio.h>
#include <string.h>

void swap(char *a, char *b);

int main() {
//	���ﲻ��ʹ�� char *a = "abc"�� ��ΪC��ֹ���ַ�������ת����ָ��
	char a[] = "abc";
	char b[] = "bcd";
	char c[] = "efg";
	if (strcmp(a, b) < 0)
		swap(a, b);
	if (strcmp(b, c) < 0)
		swap(b, c);
	if (strcmp(a, b) < 0)
		swap(a, b);
	printf("%s %s %s\n", a, b, c);
}

void swap(char *a, char *b) {
//	����ע�ⲻ�ܽ��������ַ�����ָ�룬��Ϊ�������ָ�룬�൱��ֻ�����������βε�ֵ����������ַ
//  ��������һ��Ҫ�ѵ�ַָ����ڴ��е����ݽ����ſ���
	char temp[20];
	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);
}