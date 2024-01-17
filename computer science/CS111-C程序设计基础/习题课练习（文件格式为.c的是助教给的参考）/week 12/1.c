#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 0;
	scanf("%d", &n);
	double *score = (double *)malloc(sizeof(double) * n);
	double sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lf", &score[i]);
		sum += score[i];
	}
	printf("ave = %lf", sum / n);
	return 0;
}