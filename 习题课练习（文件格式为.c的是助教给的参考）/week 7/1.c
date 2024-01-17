#include <stdio.h>

int main() {
	char mes[100];
	gets(mes); // VS: gets_s(mes,100)
	for (int i = 0; i < 100; i++) {
		if (mes[i] >= 'a' && mes[i] <= 'z')
			mes[i] -= 32;
		if (mes[i] == '\0')
			break; // 如果为'\0'，表示字符串结束，后面不必再进行判断，所以直接跳出循环。
		switch (mes[i]) {
			case 'A':
				mes[i] = '4';
				break;
			case 'B':
				mes[i] = '8';
				break;
			case 'E':
				mes[i] = '3';
				break;
			case 'I':
				mes[i] = '1';
				break;
			case 'O':
				mes[i] = '0';
				break;
			case 'S':
				mes[i] = '5';
				break;
		}
	}
	printf("%s!!!!!!!!!!", mes);
	return 0;
}