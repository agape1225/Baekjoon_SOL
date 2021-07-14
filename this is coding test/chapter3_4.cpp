#include <iostream>

using namespace std;

int main(void) {

	int N, K;
	int count = 0;

	cin >> N >> K;

	if (N % K != 0) {
		int buff;

		buff = (N / K) * K;
		count += N - buff;
		N = buff;
		

	}

	while (N != 1) {

		N /= K;
		count++;
	}

	cout << count;

}