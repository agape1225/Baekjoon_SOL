#include <stdio.h>

int main(void) {
	int input;
	scanf("%d", &input);

	for (int i = 0; i < input; i++) {
		int buff = i;
		int ans = i;
		while (buff) {
			ans += buff % 10;
			buff = buff / 10;
		}
		if (ans == input) {
			printf("%d", i);
			return 0;
		}
	}
	printf("0");

	return 0;

}