#include <iostream>
#include <queue>

using namespace std;

char map[600][600];
bool visited[600][600] = { 0 };
int N, M;

int dir_row[4] = { 0, 1, 0, -1 };
int dir_col[4] = { 1, 0, -1, 0 };

bool check_range(int row, int col) {
	if (row >= N || row < 0 || col >= M || col < 0)
		return false;
	return true;
}

int main(void) {

	int start_row, start_col;
	queue<pair<int, int>> q;
	int count = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];

			if (map[i][j] == 'I') {
				start_row = i;
				start_col = j;

			}
		}
	}

	visited[start_row][start_col] = true;
	q.push(make_pair(start_row, start_col));

	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int buff_row = row + dir_row[i];
			int buff_col = col + dir_col[i];

			if (check_range(buff_row, buff_col) 
				&& !visited[buff_row][buff_col]
				&& map[buff_row][buff_col] != 'X') {
				if (map[buff_row][buff_col] == 'P') {
					count++;
					
				}
				visited[buff_row][buff_col] = true;
				q.push(make_pair(buff_row, buff_col));
			}
		}
	}

	if (count == 0)
		cout << "TT";
	else
		cout << count;

	return 0;

}