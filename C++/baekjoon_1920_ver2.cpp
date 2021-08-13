#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> nums;
	int N, M;
	int buff;

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> buff;
		nums.push_back(buff);

	}

	cin >> M;
	sort(nums.begin(), nums.end());
	
	for (int i = 0; i < M; i++) {

		cin >> buff;

		if (binary_search(nums.begin(), nums.end(), buff))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';

	}

	return 0;

}