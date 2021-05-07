#include <cstdio>
#define SIZE 250000

int bord[SIZE];


int main(void) {

	int row, col;
	int B;
	
	int max = 0;
	int min = 256;

	scanf_s("%d %d %d", &row, &col, &B);

	for (int i = 0; i < row * col; i++) {
		scanf_s("%d", &bord[i]);

		if (max < bord[i])
			max = bord[i];
		if (min > bord[i])
			min = bord[i];

	}
	
	int ans_time = -1;
	int ans_data = -1;
	

	for (int i = min; i <= max; i++) {
		int b = B;
		int data = i;
		int time = 0;

		for (int j = 0; j < row * col; j++) {
			if (data < bord[j]) {

				time += ((bord[j] - data) * 2);
				b += (bord[j] - data);
			}
			else if (data > bord[j]) {
				time += data - bord[j];
				b -= (data - bord[j]); 
			}
		}

		if (b >= 0) {
			if (ans_time == -1) {
				ans_time = time;
				ans_data = data;
			}
			else if (ans_time >= time) {
				ans_time = time;
				ans_data = data;
			}
		}

	}
	
	printf("%d %d", ans_time, ans_data);

	return 0;

}