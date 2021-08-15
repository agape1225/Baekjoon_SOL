#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int get_amount(vector<int> rc, int standard) {

	int count = 0;

	for (auto it = rc.begin(); it != rc.end(); it++) {

		if (*it - standard > 0)
			count += *it - standard;

	}

	return count;
}

int main(void) {

	int N, M;
	int buff;
	int ans = NULL;
	vector<int> ricecake;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		
		cin >> buff;
		ricecake.push_back(buff);

	}

	int left = 0;
	int right = ricecake[N - 1];
	int mid = NULL;

	while (left <= right) {

		mid = (left + right) / 2;

		buff = get_amount(ricecake, mid);

		if (M <= buff) {
			left = mid + 1;
			ans = mid;
		}
		else {
			right = mid - 1;
		}

	}

	cout << ans;

	return 0;

}