/*#include <stdio.h>

int main(void) {
	int input;
	scanf("%d", &input);

	int size = input * 2 - 1;

	for (int i = 0; i < size; i++) {
		if (i < input) {
			for (int j = 0; j < i; j++)
				printf(" ");
			for (int j = 0; j < (input * 2) - ((i + 1) * 2 - 1); j++)
				printf("*");
		}
		else {
			for (int j = 0; j < ((input * 2) - (((i + 1) * 2 - 1) - (input * 2) + 2)) / 2; j++)
				printf(" ");
			for (int j = 0; j < ((i + 1) * 2 - 1) - (input * 2) + 2; j++)
				printf("*");
		}
		printf("\n");
	}
	return 0;
}*/

#include <stdio.h>

int main(void) {
	int input;
	scanf("%d", &input);

	int size = input * 2 - 1;

	for (int i = 0; i < size; i++) {
		if (i < input) {
			for (int j = 0; j < i; j++)
				printf(" ");
			for (int j = 0; j < size - (i * 2); j++)
				printf("*");
		}
		else {
			for (int j = 0; j < input - (i - input + 2); j++)
				printf(" ");
			for (int j = 0; j < ((i + 1) * 2 - 1) - (input * 2) + 2; j++)
				printf("*");
		}
		printf("\n");
	}
	return 0;
}