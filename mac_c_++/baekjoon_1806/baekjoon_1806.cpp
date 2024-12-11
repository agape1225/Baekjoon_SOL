#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int N, S;
	int arr[100001];
	int sum = 0;
	int ans = 0;
	int left = 0;
	int right = 0;

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sum = arr[0];
	ans = N + 1;

	while (left <= right && right < N) {
		if (sum < S) {
			sum += arr[++right];
		}
		else {
			ans = min(ans, right - left + 1);
			sum -= arr[left++];
		}
	}

	if (ans == N + 1) {
		cout << 0;
	}
	else
	{
		cout << ans;
	}
	return 0;

}