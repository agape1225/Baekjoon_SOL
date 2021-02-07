#include <stdio.h>

int aberration(int num, int d);
int recurrence(int a, int i, int d);
int main(void) {
	int input;
	int count = 0;
	scanf("%d", &input);

	for (int i = 1; i <= input; i++) {
		if (i < 100)
			count++;
		else{
			int n1 = i / 100;
			int n2 = (i % 100) / 10;
			if (aberration(i, n2 - n1))
				count++;
		}
	}
	printf("%d", count);
	return 0;
}

int aberration(int num, int d) {
	int a = num / 100;
	num = num % 100;
	int a2 = num / 10;
	int a3 = num % 10;
	if (a2 == recurrence(a, 1, d) && a3 == recurrence(a, 2, d))
		return 1;
	else
		return 0;
}

int recurrence(int a, int i, int d) {
	return a + (i * d);
}