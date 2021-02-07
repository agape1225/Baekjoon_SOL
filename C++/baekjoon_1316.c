#include <stdio.h>
#define SIZE 100

int main(void) {

	int count = 0;
	int num;
	scanf("%d", &num);

	count = num;

	while (num) {

		char input[SIZE];
		char ans[SIZE] = {0};

		scanf("%s", input);
		
		ans[0] = input[0];

		for (int i = 1, j = 1; input[i]; i++) {

			int exist = 0;
			int contin = 0;

			if (input[i] == input[i - 1])
				contin = 1;

			for (int k = 0; ans[k]; k++) {
				if (ans[k] == input[i]) {
					exist = 1;
					break;
				}
			}

			if (exist == 0) {
				ans[j] = input[i];
				j++;
			}

			if (contin == 0 && exist == 1) {
				count--;
				break;
			}
		}
		num--;
	}

	printf("%d", count);
}