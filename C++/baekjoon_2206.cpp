#include <iostream>
#include <queue>
#include <string>
#include <utility>

using namespace std;

int map[1000][1000];
int visited[1000][1000][2] = { 0 };

int dir_row[4] = { 0, 0, 1, -1 };
int dir_col[4] = { 1, -1, 0, 0 };

int N, M;

bool check_range(int row, int col) {
	if (row < 0 || row >= N || col < 0 || col >= M)
		return false;
	return true;
}

int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string buff;
		cin >> buff;
		for (int j = 0; j < M; j++) {
			map[i][j] = buff[j] - '0';
		}
	}

	queue<pair<int, pair<int, int>>> q;
	visited[0][0][1] = 1;
	q.push(make_pair(0, make_pair(0, 1)));

	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second.first;
		int wall = q.front().second.second;
		q.pop();

		if (row == N - 1 && col == M - 1) {
			cout << visited[row][col][wall];
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int row_buff = row + dir_row[i];
			int col_buff = col + dir_col[i];

			if (check_range(row_buff, col_buff)) {

				if (map[row_buff][col_buff] == 0 && visited[row_buff][col_buff][wall] == 0) {
					visited[row_buff][col_buff][wall] = visited[row][col][wall] + 1;
					q.push(make_pair(row_buff, make_pair(col_buff, wall)));

				}

				if (map[row_buff][col_buff] == 1 && wall > 0) {
					visited[row_buff][col_buff][wall - 1] = visited[row][col][wall] + 1;
					q.push(make_pair(row_buff, make_pair(col_buff, wall - 1)));
				}

			}

		}
	}

	cout << -1;
	return 0;
}