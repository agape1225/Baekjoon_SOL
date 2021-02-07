#include <stdio.h>
#define SIZE 10000

int main(void) {
	int testCase;
	scanf("%d", &testCase);
	for (int i = 0; i < testCase; i++) {
		int n;
		scanf("%d", &n);
		int arr[SIZE];
		int ans[SIZE];

		for (int j = 2; j < n; j++)
			arr[j] = 1;
		for (int j = 2; j < n; j++) {
			for (int k = 2; k <= ((n - 1) / j); k++) {
				if (arr[k * j])
					arr[k * j] = NULL;
			}
		}

		int count = 0;

		for (int j = 2; j <= (n / 2); j++) {
			if (arr[j]) {
				int buff = n - j;
				if (arr[buff]) {
					ans[count++] = j;
				}

			}
		}

		int min = NULL;
		int num = NULL;
		min = (n - ans[0]) - ans[0];
		num = 0;
		for (int j = 0; j < count; j++) {
			if (((n - ans[j]) - ans[j]) < min) {
				min = (n - ans[j]) - ans[j];
				num = j;
			}
		}
		printf("%d %d\n", ans[num], n - ans[num]);

	}
}