#include <stdio.h>
#define SIZE 1000000

int main(void) {
	char input[SIZE];
	gets(input);

	int count = 0;
	for (int i = 0; input[i]; i++) {
		if (input[i] == ' ' && input[i + 1] != NULL)
			count++;
	}
	if (input[0] != ' ')
		count++;
	printf("%d", count);
	return 0;
}