#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char month[12][20] = {"January", "February", "March", "April", "May", "June",
	                      "July", "August", "September", "October", "November", "December"
	                     };


	int m = 0, d = 0, y = 0;
	printf("Enter a date(mm/dd/yyyy): ");
	scanf("%d/%d/%d", &m, &d, &y);

	char output[100] = "You entered the date ";
	strcat(output, month[m - 1]);
	printf("%s %d, %d", output, d, y);
	return 0;

}