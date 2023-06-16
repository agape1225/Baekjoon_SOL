#include <iostream>
#include <queue>

using namespace std;

int map[1001][1001];
int ans[1001][1001] = { 0 };

int dir_x[4] = { 1, 0, -1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };

int n, m;

bool check_range(int row, int col) {
	if (row >= n || row < 0 || col >= m || col < 0)
		return false;
	return true;
}

int main(void) {

	
	int start_row, start_col;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				start_row = i;
				start_col = j;
			}
		}
	}

	queue<pair<int, int>> q;

	q.push(make_pair(start_row, start_col));

	while (!q.empty()) {
		pair<int, int> front = q.front();
		q.pop();

		//cout << front.first << ' ' << front.second << endl;
		
		for (int i = 0; i < 4; i++) {
			int tmp_row = front.first + dir_x[i];
			int tmp_col = front.second + dir_y[i];

			//cout << tmp_row << ' ' << tmp_col << endl;

			if (check_range(tmp_row, tmp_col) &&
				map[tmp_row][tmp_col] == 1 &&
				ans[tmp_row][tmp_col] == 0 && (tmp_row != start_row || tmp_col != start_col)) 
			{
				ans[tmp_row][tmp_col] = ans[front.first][front.second] + 1;
				q.push(make_pair(tmp_row, tmp_col));
			}
		}
	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			if (map[i][j] != 0 && ans[i][j] == 0 && (i != start_row || j != start_col)) {
				ans[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;

}