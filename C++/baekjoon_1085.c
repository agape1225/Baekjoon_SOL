#include <stdio.h>

int main(void) {
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	int min1, min2;
	min1 = (x < y) ? x : y;
	min2 = (h - y) < (w - x) ? (h - y) : (w - x);
	min1 = min1 < min2 ? min1 : min2;
	printf("%d", min1);
	return 0;
}