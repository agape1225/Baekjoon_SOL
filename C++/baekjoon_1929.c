/*#include <stdio.h>
#include <math.h>

int main(void) {
	int min;
	int max;
	scanf("%d %d", &min, &max);

	for (int i = min; i < max + 1; i++) {
		int count = 0;
		int buff = (int)sqrt(i);
		for (int j = 2; j <= buff; j++) {
			if (i % j == 0)
				count++;
		}
		if (count == 0 && i != 1)
			printf("%d\n", i);
	}
	return 0;
}*/
#include <stdio.h>
#include <math.h>

int main(void) {
	int min;
	int max;
	scanf("%d %d", &min, &max);

	for (int i = min; i < max + 1; i++) {
		int count = 0;
		for (int j = 2; j < i; j++) {
			if (i % j == 0)
				count++;
		}
		if (count == 0 && i != 1)
			printf("%d\n", i);
	}
	return 0;
}
