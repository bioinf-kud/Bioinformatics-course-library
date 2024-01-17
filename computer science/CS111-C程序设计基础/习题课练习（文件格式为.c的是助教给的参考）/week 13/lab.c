#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
	char name[20];
	int ID;
	double math;
	double chinese;
	double english;
	double total;
	int rank;
};

void init(struct student *stus, int n) {
	for (int i = 0; i < n; i++) {
		stus[i].ID = i + 1;
		stus[i].rank = i + 1;
		stus[i].math = rand() % 101;
		stus[i].chinese = rand() % 101;
		stus[i].english = rand() % 101;
		stus[i].total = stus[i].math + stus[i].chinese + stus[i].english;
	}
}

void sort(struct student *stus, int n) {
	struct student w;
	for (int i = 0; i < n - 1; i++) {
		for (int k = 0; k < n - 1 - i; k++) {
			if (stus[k].total < stus[k + 1].total) {
				w = stus[k];
				stus[k] = stus[k + 1];
				stus[k + 1] = w;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		stus[i].rank = i + 1;
	}

}

int main() {
	int n = 0;

// 读取文件
	FILE *fp = fopen("name.txt", "r");
	fscanf(fp, "%d", &n);
	fgetc(fp);
	struct student *stus = (struct student *)malloc(sizeof(struct student) * n);
	for (int i = 0; i < n; i++) {
		fgets(stus[i].name, 20, fp);
		if (stus[i].name[strlen(stus[i].name) - 1] == '\n')
			stus[i].name[strlen(stus[i].name) - 1] = '\0';
	}


// 赋随机值
	init(stus, n);
	printf("Before sorting\n");
	for (int i = 0; i < n; i++) {
		printf("%d %s %lf %lf %lf %lf %d\n", stus[i].ID, stus[i].name,  stus[i].math, stus[i].chinese, stus[i].english,
		       stus[i].total, stus[i].rank);
	}

// 排序
	sort(stus, n);

	printf("After sorting\n");
	for (int i = 0; i < n; i++) {
		printf("%d %s %lf %lf %lf %lf %d\n", stus[i].ID, stus[i].name,  stus[i].math, stus[i].chinese, stus[i].english,
		       stus[i].total, stus[i].rank);
	}

	fclose(fp);
	fp = fopen("students.txt", "w");

//	输出到文件
	for (int i = 0; i < n; i++) {
		fprintf(fp, "%d %s %lf %lf %lf %lf %d\n", stus[i].ID, stus[i].name,  stus[i].math, stus[i].chinese, stus[i].english,
		        stus[i].total, stus[i].rank);
	}
	fclose(fp);
	system("students.txt");
	return 0;
}