#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	int input;
	cin >> input;

	for (int s = 0; s < input; s++) {

		vector<int> coins;
		int coinSize, targetNum;
		int dp[10001] = { 0 };
		cin >> coinSize;

		for (int i = 0; i < coinSize; i++) {
			int buff;
			cin >> buff;
			coins.push_back(buff);
		}

		cin >> targetNum;
		dp[0] = 1;

		for (int i = 0; i < coinSize; i++) {

			for (int j = coins[i]; j <= targetNum; j++) {
				dp[j] += dp[j - coins[i]];
			}

		}

		cout << dp[targetNum] << endl;

	}

}