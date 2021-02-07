#include <stdio.h>

int main(void) {
	int x1, y1, x2, y2, x3, y3;
	int x, y;
	scanf("%d %d", &x1, &y1);
	scanf("%d %d", &x2, &y2);
	scanf("%d %d", &x3, &y3);
	
	if (x1 != x2 && y1 != y2) {
		//1과 2가 대각
		x = x3 != x1 ? x1 : x2;
		y = y3 != y1 ? y1 : y2;

	}
	else if (x1 != x3 && y1 != y3) {
		//1과 3이 대각
		x = x2 != x1 ? x1 : x3;
		y = y2 != y1 ? y1 : y3;

	}
	else if (x3 != x2 && y3 != y2) {
		//2와 3이 대각
		x = x1 != x2 ? x2 : x3;
		y = y1 != y2 ? y2 : y3;

	}

	printf("%d %d", x, y);
	return 0;
}