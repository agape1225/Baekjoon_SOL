#include <iostream>
#define SIZE 1000

using namespace std;

int dp[SIZE] = { 1 };
int arr[SIZE];

int main(void) {

	int N, max, ans;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < N; i++) {
		
		max = 0;

		for (int j = 0; j < N; j++) {

			if (arr[j] > arr[i] && dp[j] > max) {
				max = dp[j];
			}

		}

		dp[i] = max + 1;
	}

	ans = 0;

	for (int i = 0; i < N; i++) {
		if (dp[i] > ans)
			ans = dp[i];
	}

	cout << ans;

}