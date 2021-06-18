#include <iostream>

using namespace std;

int main(void) {
	int N, K;
	int ans;

	cin >> N >> K;

	int sum_N = 1;
	int buff_K = 0;
	int buff_ans = 1;
	int buff = 1;

	buff_K = N;

	while (buff_K > 0) {
		sum_N = sum_N * buff_K--;
	}

	ans = sum_N;

	//cout << ans << endl;

	buff_K = N - K;

	while (buff_K > 0) {
		buff *= buff_K--;
	}

	//ans /= buff_ans;

	//cout << buff << endl;

	buff_K = K;
	buff_ans = 1;

	while (buff_K > 0) {
		buff_ans *= buff_K--;
	}

	//cout << buff_ans << endl;

	ans = ans / (buff_ans * buff);

	cout << ans;
	

	return 0;
}