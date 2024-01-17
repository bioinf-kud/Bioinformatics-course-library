#include <stdio.h>
#include <string.h>

int main() {
	char input1[100];
	printf("Enter a string: ");
	scanf("%s", input1);

	int pos = 0;
	printf("Enter the position to insert: ");
	scanf("%d", &pos);

	char input2[100];
	printf("Enter the string to insert: ");
	scanf("%s", input2);

	char tmp[100] = "";
	for (int j = pos; j < strlen(input1) + 1; j++) {
		tmp[j - pos] = input1[j];
	}

	input1[pos] = '\0';

	strcat(input1, input2);
	strcat(input1, tmp);

	printf("%s\n", input1);

	return 0;
}