#include <iostream>
#include <vector>
#include <iomanip>

#define SIZE 1025

using namespace std;

int		arr[SIZE][SIZE];
int		 dp[SIZE][SIZE];

bool check_range(int N, int tmp) {
	if (tmp < 0 || tmp >= N)
		return false;
	else
		return true;
}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			int left = 0;
			int up = 0;

			if (i == 0 && j == 0)
				dp[i][j] = arr[i][j];

			else {

				if (check_range(N, j - 1))
					left = dp[i][j - 1];
				if (check_range(N, i - 1))
					up = dp[i - 1][j];

				dp[i][j] = arr[i][j] + up + left;

				if (!(i - 1 < 0 || j - 1 < 0)) {
					dp[i][j] -= dp[i - 1][j - 1];
				}


			}
		}
	}

	/*for (int i = 0; i < N; i++)
		cout << "-----";
	cout << endl << endl;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << setw(3) << dp[i][j] << ' ';
		}

		cout << endl;
	}

	cout << endl << endl;
	for (int i = 0; i < N; i++)
		cout << "-----";*/

	int x1, y1, x2, y2;
	int ans;

	for (int i = 0; i < M; i++) {

		cin >> x1 >> y1 >> x2 >> y2;
		x1--;
		y1--;
		x2--;
		y2--;

		ans = dp[x2][y2];

		if (x1 - 1 >= 0) {
			ans -= dp[x1 - 1][y2];
		}

		if (y1 - 1 >= 0) {
			ans -= dp[x2][y1 - 1];
		}

		if (x1 - 1 >= 0 && y1 - 1 >= 0) {
			ans += dp[x1 - 1][y1 - 1];
		}

		cout << ans << '\n';

	}

	return 0;

}