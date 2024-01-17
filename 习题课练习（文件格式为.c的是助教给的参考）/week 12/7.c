#include <stdio.h>

int main() {
	FILE *fp = fopen("test.txt", "r");
	char line[20];
	int a, b, c;

	fscanf(fp, "%d %d %s", &a, &b, line);
	fprintf(stdout, "%s", line);  // String1

//	fgets(line, 20, fp);
//	fprintf(stdout, "%s\n", line);  // '\n'

	fgets(line, 20, fp);
	fprintf(stdout, "%s", line);     // String2
}
