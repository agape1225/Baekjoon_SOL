#include <iostream>
#include <queue>

using namespace std;

int dir_x[4] = { 0, 1, 0, -1 };
int dir_y[4] = { 1, 0, -1, 0 };

int M, N, K;
bool arr[51][51] = { 0 };

bool check_range(int x, int y) {
	if (x < 0 || x >= M || y < 0 || y >= N)
		return false;

	return arr[x][y];
}

int main(void) {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {

		int row, col;
		int count = 0;
		queue<pair<int, int>> q;

		cin >> M >> N >> K;
		
		for (int i = 0; i < K; i++) {
			cin >> row >> col;
			arr[row][col] = 1;
		}

		//전체 탐색 시작
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {

				//BFS 시작
				if (arr[i][j] == 1) {
					count++;

					//방문처리
					arr[i][j] = 0;
					q.push(make_pair(i, j));

					while (!q.empty()) {
						int current_x = q.front().first;
						int current_y = q.front().second;
						q.pop();

						for (int k = 0; k < 4; k++) {
							int next_x = current_x + dir_x[k];
							int next_y = current_y + dir_y[k];

							if (check_range(next_x, next_y)) {
								//방문처리
								arr[next_x][next_y] = 0;
								//queue에 push
								q.push(make_pair(next_x, next_y));
							}
						}

					}

				}

			}
		}
		cout << count << endl;
	}

	return 0;
}