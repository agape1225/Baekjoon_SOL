#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	int N, K;
	vector<int> arr;

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		arr.push_back(i);
	
	int index = 0;
	int count = K - 1;
	bool start = true;

	cout << '<';

	for (int i = 0; i < N; i++) {

		while (count != 0) {

			index++;
			if (index == N)
				index = 0;

			if (arr[index] != 0)
				count--;
		}

		if (start) {
			cout << arr[index];
			start = false;
		}
		else
			cout << ", " << arr[index];

		arr[index] = 0;
		count = K;
	}

	cout << '>';

	return 0;

}