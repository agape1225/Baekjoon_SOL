#include <stdio.h>

int main(void) {

	int up, down, max;
	int sum = 0, count;
	scanf("%d %d %d", &up, &down, &max);

	int upForDay = up - down;

	if (up > max)
		count = 1;

	else {
		count = max / upForDay;
		if (max % upForDay)
			count++;
		else {
			count--;
		}
	}
	printf("%d", count);

	return 0;
}