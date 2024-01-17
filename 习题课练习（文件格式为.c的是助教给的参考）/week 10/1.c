#include <stdio.h>


void swap(int *a, int *b);

int main() {
	int a = 4, b = 5, c = 3;
	if (a > b)
		swap(&a, &b);
	if (b > c)
		swap(&b, &c);
	if (a > b)
		swap(&a, &b);
	printf("%d %d %d\n", a, b, c);
}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}