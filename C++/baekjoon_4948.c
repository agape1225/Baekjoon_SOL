#include <stdio.h>
#define SIZE 246912

int main(void) {
	while (1) {
		int input;
		scanf("%d", &input);
		if (input == 0)
			return 0;
		int arr[SIZE];
		int min = input + 1;
		int max = input * 2;

		for (int i = min; i <= max; i++)
			arr[i] = 1;

		int count = max - min + 1;


		for (int i = 2; i < min; i++) {
			int begin = min / i;
			if (min % i)
				begin++;
			int end = max / i;
			for (int j = begin; j < end + 1; j++) {
				if (arr[j * i]) {
					arr[j * i] = NULL;
					count--;
				}
			}
		}

		printf("%d\n", count);
	}
}