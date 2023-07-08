#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> solution;

int main(void) {
	
	
	int N;
	int right, left;
	int ans_right, ans_left;
	long long ans = 9876543210;

	cin >> N;

	for (int i = 0; i < N; i++) {
		long long buff;
		cin >> buff;
		solution.push_back(buff);
	}

	right = N - 1;
	left = 0;

	while (left < right) {

		long long tmp = solution[right] + solution[left];

		if (abs(ans) > abs(tmp)) {
			ans_left = left;
			ans_right = right;
			ans = tmp;
		}
		
		if (tmp == 0)
			break;

		if (tmp > 0) {
			right--;
		}
		else {
			left++;
		}
	}

	cout << solution[ans_left] << ' ' << solution[ans_right];

	return 0;

}