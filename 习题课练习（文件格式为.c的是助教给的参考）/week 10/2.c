#include <stdio.h>
#include <string.h>

void swap(char *a, char *b);

int main() {
//	这里不能使用 char *a = "abc"， 因为C禁止将字符串常量转换成指针
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
//	这里注意不能交换两个字符串的指针，因为如果交换指针，相当于只交换了两个形参的值，即两个地址
//  所以这里一定要把地址指向的内存中的内容交换才可以
	char temp[20];
	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);
}