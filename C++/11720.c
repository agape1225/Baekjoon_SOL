#include <stdio.h>
#define SIZE 100

int main(void) {
	int buff;
	char numStr[SIZE];
	int sum = 0;

	scanf("%d", &buff);
	scanf("%s", numStr);
	
	for (int i = 0; i < buff; i++)
		sum = sum + (numStr[i] - '0');
	printf("%d", sum);
	return 0;
}

/*#include <stdio.h>

int main(void) {
	int buff;
	int num;
	int sum = 0;

	scanf("%d", &buff);
	scanf("%d", &num);

	for (int i = 0; i < buff; i++) {
		sum = sum + (num % 10);
		num = num / 10;
	}
	
	printf("%d", sum);

	return 0;
}*/