#include <iostream>
//#include <vector>
#define SIZE 1000

using namespace std;

int increase[SIZE] = { 0 };
int decrease[SIZE] = { 0 };
int arr[SIZE] = { 0 };

int main(void) {

	int N, count;
	int ans = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> arr[i];

	}

	for (int i = 0; i < N; i++) {

		count = 0;

		for (int j = 0; j < i; j++) {
			
			if (arr[j] < arr[i] && increase[j] > count) {
				count = increase[j];
			}

		}

		increase[i] = count + 1;

	}

	for (int i = N - 1; i > -1; i--) {

		count = 0;

		for (int j = N - 1; j > i; j--) {

			if (arr[j] < arr[i] && decrease[j] > count) {
				count = decrease[j];
			}

		}

		decrease[i] = count + 1;

	}

	int buff;

	/*for (int i = 0; i < N; i++) {
		cout << increase[i] << ' ';
	}
	cout << endl;

	for (int i = 0; i < N; i++) {
		cout << decrease[i] << ' ';
	}
	cout << endl;*/

	for (int i = 0; i < N; i++) {
		
		buff = increase[i] + decrease[i];

		if (ans < buff)
			ans = buff;

	}

	cout << ans - 1;

	return 0;

}