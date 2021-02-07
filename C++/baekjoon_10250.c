#include <stdio.h>

int main(void) {
	int testCase;
	scanf("%d", &testCase);
	for (int i = 0; i < testCase; i++) {
		int h, w, n;
		scanf("%d %d %d", &h, &w, &n);
		int layer = n % h;
		int roomNum = (n / h) + 1;
		if (layer == 0) {
			layer = h;
			roomNum--;
		}
		int result = (100 * layer) + roomNum;
		printf("%d\n", result);
	}
	return 0;
}