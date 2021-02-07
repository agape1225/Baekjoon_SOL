#include <stdio.h>
#define SIZE 20

int main(void) {
	char input[SIZE];
	int num;
	int test_size;
	scanf("%d", &test_size);
	for (int i = 0; i < test_size; i++) {
		scanf("%d %s", &num, input);
		for (int i = 0; input[i]; i++) {
			for (int j = 0; j < num; j++)
				printf("%c", input[i]);
		}
		printf("\n");
	}
	return 0;
}