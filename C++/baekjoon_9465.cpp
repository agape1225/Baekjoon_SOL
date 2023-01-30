#include <iostream>
#include <algorithm>

using namespace std;

int graph[2][100000];
int cache[2][100000];

int main(void) {

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {

		int n;
		cin >> n;

		for (int i = 0; i < n; i++){
			cin >> graph[0][i];
		}

		for (int i = 0; i < n; i++) {
			cin >> graph[1][i];
		}

		cache[0][0] = graph[0][0];
		cache[1][0] = graph[1][0];

		if (n == 1) {
			cout << max(cache[0][0], cache[1][0]) << '\n';
			continue;
		}

		cache[0][1] = graph[0][1] + graph[1][0];
		cache[1][1] = graph[1][1] + graph[0][0];

		if (n == 2) {
			cout << max(cache[0][1], cache[1][1]) << '\n';
			continue;
		}

		for (int i = 2; i < n; i++) {
			cache[0][i] = max(cache[1][i - 1], cache[1][i - 2]) + graph[0][i];
			cache[1][i] = max(cache[0][i - 1], cache[0][i - 2]) + graph[1][i];
		}

		cout << max(cache[0][n - 1], cache[1][n - 1]);
		cout << '\n';

	}
	return 0;
}