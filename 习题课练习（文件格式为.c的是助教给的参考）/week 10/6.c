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
//	指定两个指针，一个指向字符串的开头，一个指向字符串的末尾
	char *begin = old_str;
	char *end = old_str + strlen(old_str) - 1;

//	让开头指针停留在第一个非空格的字符上
	while (*begin == ' ')
		begin++;

//	让结尾指针停留在最后一个非空格的字符上
	while (*end == ' ')
		end--;

//  从begin指针开始复制，复制end-begin+1个字符
	strncpy(new_str, begin, end - begin + 1);
}