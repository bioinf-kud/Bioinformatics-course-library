#include <stdio.h>

int main() {
	FILE *fptr_in;
	FILE *fptr_out;
	fptr_in = fopen("scores.txt", "r");
	int n = 0;
	fscanf(fptr_in, "%d", &n);
//	printf("%d\n", n);

	int num = 0, score_a = 0, score_b = 0, score_c = 0;

	fptr_out = fopen("average.txt", "w");
	for (int i = 0; i < n; i++) {
		fscanf(fptr_in, "%d %d %d %d", &num, &score_a, &score_b, &score_c);
//		printf("%d %d %d %d\n", num, score_a, score_b, score_c);
		double average = 0.0;
		average = (score_a + score_b + score_c) / 3.0;
		fprintf(fptr_out, "%lf\n", average);
	}

	fclose(fptr_in);
	fclose(fptr_out);

	return 0;
}