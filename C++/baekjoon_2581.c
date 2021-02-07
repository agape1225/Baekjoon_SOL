#include <stdio.h>

int main(void) {
	int min, max;
	scanf("%d", &min);
	scanf("%d", &max);
	int sum = 0;
	int least = NULL;

	for (int i = min; i < max + 1; i++) {
		int count = 0;
		for (int j = 1; j < i + 1; j++) {
			if (i % j == 0)
				count++;

		}
		if (sum == 0 && count == 2)
			least = i;
		if (count == 2)
			sum += i;
		
	}
	if (least) {
		printf("%d\n%d", sum, least);
	}
	else
		printf("-1");
}