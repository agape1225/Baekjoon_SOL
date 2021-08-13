#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N, K;
	cin >> N >> K;

	long long left = 1;
	long long right = N * N;
	long long mid, cnt, ans = 1;

	while (left <= right) {

		mid = (left + right) / 2;
		cnt = 0;

		for (int i = 1; i <= N; i++) {

			cnt += min(N, (mid / i));
		}

		if (K <= cnt) {
			right = mid - 1;
			ans = mid;
		}
		else {
			left = mid + 1;
		}

	}

	cout << ans << endl;

	return 0;

}