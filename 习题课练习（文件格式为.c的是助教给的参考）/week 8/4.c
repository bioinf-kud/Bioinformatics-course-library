#include <stdio.h>
#include <string.h>

int main() {
	char max[20], min[20];
	char tmp[20];

	printf("Enter word: ");
	scanf("%s", max);
	strcpy(min, max);
	while (1) {
		printf("Enter word: ");
		scanf("%s", tmp);

		if (strcmp(max, tmp) < 0) {
			strcpy(max, tmp);
		}

		if (strcmp(min, tmp) > 0) {
			strcpy(min, tmp);
		}

		if (strlen(tmp) == 4)
			break;
	}

	printf("Smallest word: %s\n", min);
	printf("Largest word: %s", max);

	return 0;

}