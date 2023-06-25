#include <iostream>
#include <algorithm>

using namespace std;

int cache[100000][3];
int bord[100000][3];
int N;
int max_ans = NULL;
int min_ans = NULL;

int main(void) {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> bord[i][0] >> bord[i][1] >> bord[i][2];
	}

	cache[0][0] = bord[0][0];
	cache[0][1] = bord[0][1];
	cache[0][2] = bord[0][2];

	for (int i = 1; i < N; i++) {
		cache[i][0] = bord[i][0] + max(cache[i - 1][0], cache[i - 1][1]);
		cache[i][1] = bord[i][1] + max(max(cache[i - 1][2], cache[i - 1][1]), cache[i - 1][0]);
		cache[i][2] = bord[i][2] + max(cache[i - 1][2], cache[i - 1][1]);
	}

	max_ans = max(max(cache[N - 1][0], cache[N - 1][1]), cache[N - 1][2]);

	for (int i = 1; i < N; i++) {
		cache[i][0] = bord[i][0] + min(cache[i - 1][0], cache[i - 1][1]);
		cache[i][1] = bord[i][1] + min(min(cache[i - 1][2], cache[i - 1][1]), cache[i - 1][0]);
		cache[i][2] = bord[i][2] + min(cache[i - 1][2], cache[i - 1][1]);
	}

	min_ans = min(min(cache[N - 1][0], cache[N - 1][1]), cache[N - 1][2]);

	cout << max_ans << ' ' << min_ans;

	return 0;
}