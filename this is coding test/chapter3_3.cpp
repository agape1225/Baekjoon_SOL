#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	vector<int> arr[100];
	vector<int> ans;
	int N, M;
	int buff;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {

			cin >> buff;

			arr[i].push_back(buff);

		}

	}

	int min = 10001;

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {

			if (arr[i][j] < min)
				min = arr[i][j];

		}

		ans.push_back(min);
		min = 10001;

	}

	int max = 0;

	for (int i = 0; i < N; i++) {

		if (max < ans[i])
			max = ans[i];

	}

	cout << max;

	return 0;

}