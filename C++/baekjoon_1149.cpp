#include  <iostream>
#define SIZE 1001

using namespace std;

int rgb[SIZE][3];
int dp[SIZE][3];

int main(void) {
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> rgb[i][0];
		cin >> rgb[i][1];
		cin >> rgb[i][2];

	}

	dp[0][0] = rgb[0][0];
	dp[0][1] = rgb[0][1];
	dp[0][2] = rgb[0][2];


	for (int i = 1; i < N; i++) {

		

		dp[i][0] = rgb[i][0] + (dp[i - 1][1] < dp[i - 1][2] ? dp[i - 1][1] : dp[i - 1][2]);
		dp[i][1] = rgb[i][1] + (dp[i - 1][2] < dp[i - 1][0] ? dp[i - 1][2] : dp[i - 1][0]);
		dp[i][2] = rgb[i][2] + (dp[i - 1][1] < dp[i - 1][0] ? dp[i - 1][1] : dp[i - 1][0]);

		//cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << endl;

	}

	int min = 1000000;

	for (int i = 0; i < 3; i++) {
		if (min > dp[N - 1][i])
			min = dp[N - 1][i];
	}

	cout << min;

	return 0;

}