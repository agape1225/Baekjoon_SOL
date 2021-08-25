#include <iostream>
#define SIZE 300

using namespace std;

int dp[SIZE];

int main(void) {

	int step[SIZE];
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> step[i];
	}

	dp[0] = step[0];
	dp[1] = step[0] + step[1];
	dp[2] = step[0] + step[2] > step[1] + step[2] ? step[0] + step[2] : step[1] + step[2];

	int buff1 = step[0] + step[1];
	int buff2 = step[0] + step[2];
	int buff3 = step[2] + step[1];
	
	/*if (buff1 > buff2) {
		if (buff1 > buff3) {
			dp[2] = buff1;
		}
		else {
			dp[2] = buff3;
			dir = true;
		}
	}
	else {
		if (buff2 > buff3) {
			dp[2] = buff2;
		}	
		else {
			dp[2] = buff3;
		}
			
	}*/

	for (int i = 3; i < N; i++) {

		dp[i] += step[i] + (step[i - 1] + dp[i - 3] > dp[i - 2] ? step[i - 1] + dp[i - 3] : dp[i - 2] );
	}

	cout << dp[N - 1];

	return 0;

}