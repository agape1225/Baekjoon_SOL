#include <iostream>

using namespace std;

int main(void) {

	int cache[101][10] = { 0 };
	int N;
	cin >> N;

	for (int i = 1; i < 10; i++) {
		cache[1][i] = 1;
	}

	for (int i = 2; i < 101; i++) {
		for (int j = 0; j < 10; j++) {

			if (j == 0) {
				cache[i][j] = cache[i - 1][1] % 1000000000;
			}
			else if (j == 9) {
				cache[i][j] = cache[i - 1][8] % 1000000000;
			}
			else {
				cache[i][j] = (cache[i - 1][j - 1] + cache[i - 1][j + 1]) % 1000000000;
			}

		}
	}

	long long ans = 0;

	for (int i = 0; i < 10; i++) {
		ans += cache[N][i];
	}

	cout << ans % 1000000000;

	return 0;
}