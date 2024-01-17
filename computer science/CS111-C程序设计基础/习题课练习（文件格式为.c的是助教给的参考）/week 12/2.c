#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 0;
	scanf("%d", &n);
	double **score = (double **)malloc(sizeof(double *) * n);
	for (int i = 0; i < n; i++) {
		score[i] = (double *)malloc(sizeof(double) * 4);
	}
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < 3; j++) {
			scanf("%lf", &score[i][j]);
			sum += score[i][j];
			score[i][3] = sum / 3.0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%lf ", score[i][j]);
		}
		printf("\n");
	}
	return 0;
}