#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int N, C;
	int buff;
	vector<int> house;

	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		
		cin >> buff;
		house.push_back(buff);
	}

	sort(house.begin(), house.end());

	int left, right, mid;
	int start, count;
	int ans = NULL;
	left = 1;
	right = house[N - 1];

	while (left <= right) {

		mid = (left + right) / 2;
		start = *house.begin();
		count = 1;

		for (auto it = house.begin(); it != house.end(); it++) {

			if (start + mid <= *it) {

				count++;
				start = *it;

			}

		}

		if (count < C) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
			ans = mid;
		}
	}

	cout << ans;
	
	return 0;

}