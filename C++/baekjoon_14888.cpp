#include <iostream>

using namespace std;

int maxNum = -987654321;
int minNum = 987654321;

int N;
int fac = 1;
int sufix[11] = { 0 };
int operators[4] = { 0 };

void sol(int count, int num) {

	if (count == N) {
		
		if (num > maxNum) {
			maxNum = num;
		}

		if (num < minNum) {
			minNum = num;
		}
	}
	else {

		for (int i = 0; i < 4; i++) {

			if (operators[i] > 0) {
				operators[i]--;

				if (i == 0) {			// µ¡¼À
					sol(count + 1, num + sufix[count]);
				}
				else if (i == 1) {		//»¬¼À
					sol(count + 1, num - sufix[count]);
				}
				else if (i == 2) {		//°ö¼À
					sol(count + 1, num * sufix[count]);
				}
				else {					//³ª´°¼À
					sol(count + 1, num / sufix[count]);
				}
				operators[i]++;
			}
		}

		
	}
}

int main(void) {
	

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> sufix[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> operators[i];
	}

	/*for (int i = 1; i < N; i++) {
		fac *= i;
	}*/

	sol(1, sufix[0]);

	cout << maxNum << endl;
	cout << minNum << endl;

	return 0;

}