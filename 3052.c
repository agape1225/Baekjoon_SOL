#include <stdio.h>

int main(void) {

	int num_list[42] = { 0 };
	int nums[10];
	int count = 0;


	for (int i = 0; i < 10; i++) {

		int plate;

		scanf("%d", &plate);
		nums[i] = plate;

	}

	for (int i = 0; i < 10; i++) {

		int plate = nums[i] % 42;
		num_list[plate]++;

	}

	for (int i = 0; i < 42; i++) {

		if (num_list[i] != 0) {

			count++;

		}

	}

	printf("%d", count);

}