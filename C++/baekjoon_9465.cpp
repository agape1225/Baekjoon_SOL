#include <iostream>

using namespace std;

int sticker[100000][2];
int cache[100000][2];

int main(void) {

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {

		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> sticker[i][0];
		}

		for (int i = 0; i < n; i++) {
			cin >> sticker[i][1];
		}

		cache[0][0] = sticker[0][0];
		cache[0][1] = sticker[0][1];

		if (n == 1) {
			cout << (cache[0][0] > cache[0][1] ? cache[0][0] : cache[0][1]) << endl;
			continue;
		}

		cache[1][0] = sticker[1][0] + sticker[0][1];
		cache[1][1] = sticker[1][1] + sticker[0][0];

		if (n == 2) {
			cout << (cache[1][0] > cache[1][1] ? cache[1][0] : cache[1][1]) << endl;
			continue;
		}

		for (int i = 2; i < n; i++) {

			int buff = cache[i - 1][1] > cache[i - 2][1] ? cache[i - 1][1] : cache[i - 2][1];
			cache[i][0] = sticker[i][0] + buff;


			buff = cache[i - 1][0] > cache[i - 2][0] ? cache[i - 1][0] : cache[i - 2][0];
			cache[i][1] = sticker[i][1] + buff;

		}
		cout << (cache[n-1][0] > cache[n-1][1] ? cache[n-1][0] : cache[n-1][1]) << endl;
		//cout << endl;
	}

	return 0;

}