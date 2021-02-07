#include <stdio.h>

int main(void) {
	int input;
	scanf("%d", &input);
	
	if (input == 1)
		printf("%d", 1);
	else {
		int i = 1;
		int num = 0;

		while (1) {
			num += 6 + ((i - 1) * 6);
			if (input <= num + 1)
				break;
			i++;
		}
		printf("%d", i + 1);
	}
	return 0;
}