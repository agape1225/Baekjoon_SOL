#include <iostream>
#define SIZE 1000

using namespace std;

int arr[SIZE];
int dp[SIZE];

int main(void) {

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> arr[i];

	}

	dp[0] = 1;
	int max;

	for (int i = 1; i < N; i++) {

		max = 0;

		for (int j = 0; j < i; j++) {

			if (arr[i] > arr[j]) {

				if (dp[j] > max)
					max = dp[j];

			}

		}

		dp[i] = max + 1;

	}

	int ans = 0;

	for (int i = 0; i < N; i++) {
		if (dp[i] > ans)
			ans = dp[i];
	}


	cout << ans;

	return 0;

}