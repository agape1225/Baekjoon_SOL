#include <iostream>

using namespace std;

int arr[100000];
int dp[100000];

int main(void) {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];

	for (int i = 1; i < n; i++) {

		dp[i] = arr[i] > dp[i - 1] + arr[i] ? arr[i] : dp[i - 1] + arr[i];

	}

	int ans = -1000;

	for (int i = 0; i < n; i++) {
		if (ans < dp[i]){
			ans = dp[i];
		}
	}

	cout << ans;

}