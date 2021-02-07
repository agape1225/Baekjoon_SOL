#include <stdio.h>

int main(void) {
	int num;
	scanf("%d", &num);

	int size = num * 2 - 1;

	for (int i = 0; i < size; i++) {
		if (i < num) {
			for (int j = 0; j <= i; j++)
				printf("*");
		}
		else {
			for (int j = 0; j < num - (i - num) - 1; j++)
				printf("*");
		}
		printf("\n");
	}
}