#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int>> stuff;
int cache[101][100001] = { 0 };

int main(void) {

	int N, K;
	int buff1, buff2;
	
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> buff1 >> buff2;
		stuff.push_back(make_pair(buff1, buff2));
	}

	for (int i = 1; i <= N; i++) {

		int W, V;

		W = stuff[i - 1].first;
		V = stuff[i - 1].second;

		for (int j = 1; j <= K; j++) {

			if (j - W >= 0) {
				cache[i][j] = max(cache[i - 1][j], cache[i - 1][j - W] + V);
			}
			else {
				cache[i][j] = cache[i - 1][j];
			}

		}

	}

	cout << cache[N][K];

	return 0;

}