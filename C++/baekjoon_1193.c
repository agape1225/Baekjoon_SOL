#include <stdio.h>

int main(void) {
	int input;
	scanf("%d", &input);
	int count = 1;
	int numerator = NULL;
	int denominator = NULL;

	while (1) {
		int sum = count + 1;

		for (int i = 1; i < sum; i++) {
			if (sum % 2) {
				denominator = i;
				numerator = sum - denominator;
			}
			else {
				numerator = i;
				denominator = sum - numerator;
			}

			if ((--input) == 0) {
				printf("%d/%d", denominator, numerator);
				return 0;
			}
		}

		count++;
	}
}