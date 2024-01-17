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

// bool型返回true或者false，即1或者0，相当于int
bool is_palindrome(char *str) {
//	创建两个指针一个指向开头一个指向结尾
	char *begin, *end;
	bool flag = true;

	int len = strlen(str);

//	前后两个指针同时往中间缩，直到两个指针相遇
	for (begin = str, end = str + len - 1; begin <= end; begin++, end--) {
//		如果有某一位不相等，说明不是回文，则直接退出循环返回false。
		if (*begin != *end) {
			flag = false;
			break;
		}
	}
//	如果循环正常结束，flag值没有改变，返回true

	return flag;
}