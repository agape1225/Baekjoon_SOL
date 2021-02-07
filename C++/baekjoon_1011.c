#include <stdio.h>

int main(void) {
	int testCase;
	scanf("%d", &testCase);
	for (int i = 0; i < testCase; i++) {
		long long start, goal;
		long count = 0;
		int max = 1;
		int min = -1;
		scanf("%d %d", &start, &goal);
		
		goal--; count++;
		//printf("%d %d", start, goal);
		while (1) {
			//printf("%d\n", start + max);
			if (start + max < goal) {
				start += max;
				count++;
				max++;
				
			}
			else {
				count++;
				break;
			}
		}
		printf("%d\n", count);

	}
}