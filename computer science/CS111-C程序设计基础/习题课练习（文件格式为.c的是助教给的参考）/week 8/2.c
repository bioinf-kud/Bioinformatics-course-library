#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char input[100];
	char output[100];
	printf("Enter the sentence: ");
	gets(input);

	// ���±�iͣ���ڵ�һ�����ǿո���ַ���
	int i = 0;
	for (i = 0; i < strlen(input); i++) {
		if (input[i] != ' ')
			break;
	}

	// ���±�i��ʼ������output��ֵ
	for (int j = 0;; j++, i++) {
		output[j] = input[i];
		// �����ǰ�ַ��������������ַ����ǿո񣬾��ж��ַ�������
		if (input[i + 1] == ' ' && input[i + 2] == ' ') {
			output[j + 1] = '\0';
			break;
		}
	}

	printf("The new sentence: %s", output);
	return 0;
}