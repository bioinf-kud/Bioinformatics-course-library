#include <stdio.h>

int main() {
	FILE *fptr;
	fptr = fopen("scores.txt", "r");
	int num = 0, score_a = 0, score_b = 0, score_c = 0;
	fscanf(fptr, "%d %d %d %d", &num, &score_a, &score_b, &score_c);
//	printf("%d %d %d %d\n", num, score_a, score_b, score_c);

	fptr = fopen("average.txt", "w");
	double average = 0.0;
	average = (score_a + score_b + score_c) / 3.0;
	fprintf(fptr, "%lf", average);

	fclose(fptr);

	return 0;
}