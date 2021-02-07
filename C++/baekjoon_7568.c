#include <stdio.h>
#define ROWS 50
#define SIZE 50

int main(void) {
	int big[ROWS][2];
	int ans[SIZE] = { 0 };
	int size;
	scanf("%d", &size);

	for (int i = 0; i < size; i++) 
		scanf("%d %d", &big[i][0], &big[i][1]);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == j)
				continue;
			if (big[i][0] < big[j][0] && big[i][1] < big[j][1])
				ans[i]++;
		}
	}

	for (int i = 0; i < size; i++)
		printf("%d ", ans[i] + 1);

	return 0;
}	