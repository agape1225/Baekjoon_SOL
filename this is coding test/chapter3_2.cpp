#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int N, M, K;
	int buff;
	vector<int> arr;

	int ans = 0;
	int count;

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {

		cin >> buff;

		arr.push_back(buff);

	}

	sort(arr.begin(), arr.end());

	//num1

	/*count = K;
	int max = N - 1;
	int index = N - 1;

	for (int i = 0; i < M; i++) {

		if (count == 0) {

			if (index != max) {

				index = max;
				count = K;

			}
			else {

				index = max - 1;
				count = 1;

			}
				

		}

		ans += arr[index];
		count--;

	}*/

	//num2

	int num1 = arr[arr.size() - 1];
	int num2 = arr[arr.size() - 2];

	int n = M / (K + 1);
	int mod = M % (K + 1);

	ans = (num1 * K + num2) * n;
	ans += num1 * mod;

	cout << ans;

}