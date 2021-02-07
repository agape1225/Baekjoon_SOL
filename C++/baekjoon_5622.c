#include <stdio.h>
#define SIZE 15
#pragma warning(disable:4996)

int main(void) {
	char input[SIZE];
	scanf("%s", input);

	int count = 0;

	for (int i = 0; input[i]; i++) {
		if (input[i] < 'D')
			count += 3;
		else if (input[i] < 'G')
			count += 4;
		else if (input[i] < 'J')
			count += 5;
		else if (input[i] < 'M')
			count += 6;
		else if (input[i] < 'P')
			count += 7;
		else if (input[i] < 'T')
			count += 8;
		else if (input[i] < 'W')
			count += 9;
		else if (input[i] < 'Z' + 1)
			count += 10;
	}
	printf("%d", count);
	return 0;
}