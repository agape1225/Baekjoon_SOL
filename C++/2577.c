#include <stdio.h>
#define SIZE 10

int main(void) {
	int num1, num2, num3;
	int arr[SIZE] = { 0 };
	scanf("%d", &num1);
	scanf("%d", &num2);
	scanf("%d", &num3);


	int sum = num1 * num2 * num3;

	while (sum) {
		int buff = sum % 10;
		arr[buff]++;
		sum = sum / 10;
	}

	for (int i = 0; i < SIZE; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}