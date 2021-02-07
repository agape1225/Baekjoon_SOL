#include <stdio.h>

int main(void) {
	int N;
	int decimal = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int input;
		int count = 0;
		scanf("%d", &input);
		for (int i = 1; i < input + 1; i++) {
			if (input % i == 0)
				count++;
		}
		if (count == 2)
			decimal++;
	}
	printf("%d", decimal);
	return 0;
}