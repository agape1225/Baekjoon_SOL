#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

int main(void) {
	int input;
	scanf("%d", &input);

	for (int i = 0; i < input; i++) {
		int num;
		int score[SIZE];
		scanf("%d", &num);
		int sum = 0;
		for (int i = 0; i < num; i++) {
			scanf("%d", &score[i]);
			sum = sum + score[i];
		}
		float average = sum / num;
		int count = 0;
		for (int i = 0; i < num; i++) {
			if (score[i] > average)
				count++;
		}
		float result = count * 100.0 / num;
		printf("%.3lf%c\n", result,'%');
	}
}