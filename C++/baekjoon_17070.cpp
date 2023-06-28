#include <iostream>
#include <queue>

using namespace std;

/*
* code 1: 가로
* code 2: 대각선
* code 3: 세로
*/

int N;
int house[16][16];

bool check_range(int row, int col) {
	if (row < 0 || row >= N || col < 0 || col >= N || house[row][col] == 1)
		return false;
	return true;
}

int main(void) {
	
	int ans = 0;
	
	queue<pair<pair<int, int>, int>> q;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> house[i][j];
		}
	}

	q.push(make_pair(make_pair(0, 1), 1));

	while (!q.empty()) {
		int row = q.front().first.first;
		int col = q.front().first.second;
		int dir = q.front().second;
		q.pop();

		if (row == N - 1 && col == N - 1) {
			ans++;
			continue;
		}

		if (dir == 1) {							//가로
			if (check_range(row, col + 1)) {
				q.push(make_pair(make_pair(row, col + 1), 1));
			}

			if (check_range(row, col + 1) && 
				check_range(row + 1, col + 1) && 
				check_range(row + 1, col)) {

				q.push(make_pair(make_pair(row + 1, col + 1), 2));
			}

		}
		else if (dir == 2) {					//대각선

			if (check_range(row, col + 1)) {
				q.push(make_pair(make_pair(row, col + 1), 1));
			}

			if (check_range(row, col + 1) &&
				check_range(row + 1, col + 1) &&
				check_range(row + 1, col)) {

				q.push(make_pair(make_pair(row + 1, col + 1), 2));
			}

			if (check_range(row + 1, col)) {
				q.push(make_pair(make_pair(row + 1, col), 3));
			}

		}
		else if (dir == 3) {					//세로


			if (check_range(row, col + 1) &&
				check_range(row + 1, col + 1) &&
				check_range(row + 1, col)) {

				q.push(make_pair(make_pair(row + 1, col + 1), 2));
			}

			if (check_range(row + 1, col)) {
				q.push(make_pair(make_pair(row + 1, col), 3));
			}
		}
	}
	cout << ans;

	return 0;
}