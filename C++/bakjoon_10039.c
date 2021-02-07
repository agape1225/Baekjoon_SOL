#include <stdio.h>

int main(void) {

	int result = 0;

	for (int i = 0; i < 5; i++) {
		int buff;
		scanf("%d", &buff);
		if (buff < 40)
			result = result + 40;
		else
			result = result + buff;
	}
	printf("%d", result / 5);
}