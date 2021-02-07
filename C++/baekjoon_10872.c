#include <stdio.h>

int fac(int n);

int main(void) {
	int input;
	scanf("%d", &input);
	input = fac(input);
	printf("%d", input);
}

int fac(int n) {
	if (n <= 1)
		return 1;
	else
		return n * fac(n - 1);
}