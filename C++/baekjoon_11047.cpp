#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	int N, K;
	int buff, index;
	int count = 0;
	vector<int> coin;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {

		cin >> buff;
		coin.push_back(buff);

	}

	index = N - 1;

	while (K) {

		while (coin[index] > K)
			index--;

		count += K / coin[index];
		K %=  coin[index];

	}

	cout << count;

	return 0;

}