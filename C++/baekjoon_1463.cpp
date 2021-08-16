#include <iostream>
#include <vector>
#define SIZE 1000001

using namespace std;

int dp[SIZE] = { 0 };

int main(void) {
	
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {

		if(i + 1 <= 1000000){

			if (dp[i + 1] == 0)
				dp[i + 1] = dp[i] + 1;
			else if (dp[i + 1] > dp[i] + 1)
				dp[i + 1] = dp[i] + 1;

		}


		if (i * 2 < 1000000) {
			if (dp[i * 2] == 0)
				dp[i * 2] = dp[i] + 1;
			else if (dp[i * 2] > dp[i] + 1)
				dp[i * 2] = dp[i] + 1;
		}

		if (i * 3 < 1000000) {
			if (dp[i * 3] == 0)
				dp[i * 3] = dp[i] + 1;
			else if (dp[i * 3] > dp[i] + 1)
				dp[i * 3] = dp[i] + 1;
		}


	}

	cout << dp[N];

	return 0;

}