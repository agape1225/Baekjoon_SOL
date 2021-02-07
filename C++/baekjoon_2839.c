#include <stdio.h>

int main(void) {
	int num5 = 5;
	int num3 = 3;
	int input, ans;
	int count;

	scanf("%d", &input);

	count = input / num5;

	ans = -1;

	for (int i = 1; i <= count; i++) {
		int buff = input;
		int plate = i;
		buff = buff - (i * num5);
		if (buff % num3 == 0)
			plate += (buff / num3);
		else
			continue;
		if (ans == -1)
			ans = plate;
		else
			ans = ans > plate ? plate : ans;
	}

	if (ans == -1 && input % num3 == 0)
		ans = input / num3;

	printf("%d", ans);

	return 0;
}