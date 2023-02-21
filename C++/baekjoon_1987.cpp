#include <iostream>
#include <algorithm>

using namespace std;

int dir_row[4] = { 0, 0, 1, -1 };
int dir_col[4] = { 1, -1, 0, 0 };

int R, C;
int bord[20][20];

bool visited[26] = { 0 };

int ans = -1;

bool check_range(int i, int j) {
	if (i < 0 || i >= R || j < 0 || j >= C)
		return false;
	return true;
}

void dfs(int row, int col, int count) {

	//cout << row << ' ' << col << ' ' << endl;

	ans = max(ans, count);

	for (int i = 0; i < 4; i++) {

		int row_buff = row + dir_row[i];
		int col_buff = col + dir_col[i];

		if (check_range(row_buff, col_buff)) {
			int alpabet = bord[row_buff][col_buff];
			if (!visited[alpabet - 'A']) {
				visited[alpabet - 'A'] = true;
				dfs(row_buff, col_buff, count + 1);
				visited[alpabet - 'A'] = false;

			}
		}

	}

}

int main(void) {
	cin >> R >> C;
	string buff;

	for (int i = 0; i < R; i++) {
		cin >> buff;
		for (int j = 0; j < C; j++) {
			bord[i][j] = buff[j];
		}
	}

	visited[bord[0][0] - 'A'] = true;
	dfs(0, 0, 1);

	cout << ans;

	return 0;

}