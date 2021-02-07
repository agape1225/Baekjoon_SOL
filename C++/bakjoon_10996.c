#include <stdio.h>

int main(void) {
	int input;
	scanf("%d", &input);

	int down = input - (input / 2);
	int up = input / 2;
	
	if (input != 1)
		input = input * 2;

	for (int i = 0; i < input; i++) {
		if (i % 2) {
			for (int j = 0; j < up; j++)
				printf(" *");
		}
		else {
			for (int j = 0; j < down; j++)
				printf("* ");
		}
		printf("\n");
	}
	return 0;
}