#include <iostream>
#include <cstdio>

#define SIZE 6

using namespace std;

int main(void) {
	int N;
	int dice[SIZE];
	

	long long result = 0;
	long long k;

	//scanf_s("%d", &N);
	cin >> N;

	

	

	for (int i = 0; i < SIZE; i++) {
		//scanf_s("%d", &dice[i]);
		cin >> dice[i];
	}

	if (N == 1) {
		int max = dice[0];
		int index = 0;

		for (int i = 0; i < SIZE; i++) {
			if (max < dice[i]) {
				max = dice[i];
				index = i;
			}
				
		}

		int sum = 0;

		for (int i = 0; i < SIZE; i++) {
			if (i == index)
				continue;
			sum += dice[i];
		}

		printf("%d", sum);

	}
	else {
		k = N - 2;
		int min = dice[0];

		for (int i = 0; i < SIZE; i++) {
			if (dice[i] < min)
				min = dice[i];
		}

		int doubleMin = dice[0] + dice[1];

		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				if (i != j && i + j != 5) {
					if (dice[i] + dice[j] < doubleMin)
						doubleMin = dice[i] + dice[j];
				}
			}
		}

		int tripleMin = dice[0] + dice[1] + dice[2];

		if (tripleMin > dice[0] + dice[1] + dice[3])
			tripleMin = dice[0] + dice[1] + dice[3];

		if (tripleMin > dice[0] + dice[4] + dice[3])
			tripleMin = dice[0] + dice[4] + dice[3];

		if (tripleMin > dice[0] + dice[4] + dice[2])
			tripleMin = dice[0] + dice[4] + dice[2];

		if (tripleMin > dice[5] + dice[1] + dice[3])
			tripleMin = dice[5] + dice[1] + dice[3];

		if (tripleMin > dice[5] + dice[1] + dice[2])
			tripleMin = dice[5] + dice[1] + dice[2];

		if (tripleMin > dice[5] + dice[4] + dice[3])
			tripleMin = dice[5] + dice[4] + dice[3];

		if (tripleMin > dice[5] + dice[4] + dice[2])
			tripleMin = dice[5] + dice[4] + dice[2];

		//cout << doubleMin << endl << tripleMin << endl;

		result += ((N - 2) * (N - 2));
		//printf("%d \n", result);
		//cout << result << endl << endl;

		result += (N - 2);
		//cout << result << endl << endl;

		result *= min * 4;
		//cout << result << endl << endl;

		result += (N - 2) * (N - 2) * min;
		//cout << result << endl << endl;

		result += (N - 1) * 4 * doubleMin;
		//cout << result << endl << endl;

		result += (N - 2) * 4 * doubleMin;
		//cout << result << endl << endl;

		result += 4 * tripleMin;

		/*printf("%d",
			((((N - 2) * (N - 2)) + (N - 2)) * min * 4) + ((N - 2) * (N - 2) * min) +
			((N - 2) * (N - 2) * min) + ((N - 1) * 4 * doubleMin) + ((N - 2) * 4 * doubleMin)
		);*/

		printf("%lld",

			(min*k*(5 * k + 4)) + 4 * ((N - 1) * doubleMin + k * doubleMin) + 4 * tripleMin

		);
	}
	

	return 0;

	
}