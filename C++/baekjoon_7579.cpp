#include <iostream>
#include <algorithm>

using namespace std;

int memory[100];
int cost[100];
int cache[101][10001] = { 0 };

int main(void) {

	int N, M;
	int sum = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> memory[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> cost[i];
		sum += cost[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= sum; j++) {
			if (j - cost[i] >= 0) {
				cache[i + 1][j] = max(cache[i + 1][j - cost[i]] + memory[i], cache[i + 1][j]);
			}
			cache[i + 1][j] = max(cache[i + 1][j], cache[i][j]);
		}
	}
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j <= sum; j++) {
	//		cout << cache[i + 1][j] << ' ';
	//	}
	//	cout << endl;
	//}

	for (int i = 0; i <= sum; i++) {
		if (cache[N + 1][i] >= M) {
			cout << i << endl;
			break;
		}
	}

	return 0;
}