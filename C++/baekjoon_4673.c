#include <stdio.h>
#define SIZE 10000
#include <stdlib.h>

int d(int x);
int isIn(int *list, int n);
int static compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int main(void) {
	int ans[SIZE] = {0};
	int count = 0;
	int i;
	for (i = 1; i < SIZE; i++) {
		ans[i - 1] = d(i);
		count++;
	}
	qsort(ans, SIZE, sizeof(int), compare);
	for (int i = 1; i <= SIZE; i++) {
		if (!isIn(ans, i))
			printf("%d\n", i);
	}
	return 0;
}

int d(int x) {
	int ans = x;
	while (x) {
		ans = ans + (x % 10);
		x = x / 10;
	}
	return ans;
}

int isIn(int *list, int n) {
	while (1) {
		if (*list == n)
			return 1;
		if (*list > n)
			return 0;
		list++;
	}
}