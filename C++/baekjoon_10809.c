#include <stdio.h>
#define SIZE 100

int main(void) {
	char input[SIZE];
	char alp = 'a';
	scanf("%s", input);

	for (int i = 0; i < 26; i++) {
		int j = 0;
		while (1) {
			if (input[j] == alp) {
				printf("%d ", j);
				break;
			}
			if (input[j] == NULL) {
				printf("%d ", -1);
				break;
			}
			j++;
		}
		alp++;
	}
	return 0;
}