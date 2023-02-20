#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int lab[8][8];
//bool visited[8][8];
int N, M;
int ans = -1;
int dir_row[4] = { 0, 1, 0, -1 };
int dir_col[4] = { 1, 0, -1, 0 };

bool check_range(int i, int j) {
	if (i < 0 || i >= N || j < 0 || j >= M)
		return false;
	return true;
}

void bfs(int count, int start_row, int start_col) {

	if (count == 3) {
		
		int ans_buff = 0;
		int dir = false;
		int lab_buff[8][8];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				lab_buff[i][j] = lab[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (lab_buff[i][j] == 2) {
					queue<pair<int, int>> q;
					q.push(make_pair(i, j));

					//bfs
					while (!q.empty()) {
						pair<int, int> top = q.front();
						int row = top.first;
						int col = top.second;
						q.pop();

						for (int k = 0; k < 4; k++) {
							int buff_row = row + dir_row[k];
							int buff_col = col + dir_col[k];

							if (check_range(buff_row, buff_col) && lab_buff[buff_row][buff_col] == 0) {
								lab_buff[buff_row][buff_col] = 2;
								q.push(make_pair(buff_row, buff_col));
							}
						}
					}

					
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (lab_buff[i][j] == 0) {
					ans_buff++;
				}
			}
		}
		ans = max(ans, ans_buff);
	}
	else {
		for (int i = start_row; i < N; i++) {
			for (int j = start_col; j < M; j++) {
				if (lab[i][j] == 0) {
					lab[i][j] = 1;
					if (j + 1 == M) {
						bfs(count + 1, i + 1, 0);
					}
					else {
						bfs(count + 1, i, 0);
					}
					//bfs(count + 1, 0, 0);
					lab[i][j] = 0;
				}
			}
		}
	}

}

int main(void) {
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> lab[i][j];
			/*if (lab[i][j] == 0) {
				visited[i][j] = false;
			}
			else
				visited[i][j] = true;*/
		}
	}

	bfs(0, 0, 0);

	cout << ans;

	return 0;
}