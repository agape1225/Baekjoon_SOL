#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> stuff;
int cache[101][100001] = { 0 };


int main(void) {

	int N, K;
	int W, V;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> W >> V;
		stuff.push_back(make_pair(W, V));
	}

	for (int i = 0; i < N; i++) {
		W = stuff[i].first;
		V = stuff[i].second;

		for (int j = 1; j <= K; j++) {
			if (j - W >= 0) {
				cache[i + 1][j] = max(cache[i][j], cache[i][j - W] + V);
			}
			else {
				cache[i + 1][j] = max(cache[i + 1][j - 1], cache[i][j]);
			}

		}
	}
	
	/*for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			cout << cache[i][j] << ' ';
		}
		cout << endl;
	}*/
	
	cout << cache[N][K];


	return 0;
}