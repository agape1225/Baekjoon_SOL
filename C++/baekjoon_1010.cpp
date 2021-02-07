#include <iostream>
#include <cmath>
#define SIZE 29

using namespace std;

int main(void) {

	unsigned int ans[SIZE][SIZE] = { 0 };

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (i == 0) {
				ans[i][j] = j + 1;
			}
			else {
				for (int k = 0; k < j; k++)
					ans[i][j] += ans[i - 1][k];
			}
		}
	}


	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n, m;

		cin >> n >> m;

		cout << ans[n-1][m-1] << endl;

	}

	return 0;
}