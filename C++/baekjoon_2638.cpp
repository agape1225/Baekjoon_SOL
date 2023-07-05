#include <iostream>

using namespace std;

int cheese[100][100];
int N, M;

bool dir = false;
int dir_x[4] = { 1, 0, -1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };

bool visited[100][100];
int tmp[100][100] = { 0 };

void init_visited() {
	dir = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}
}

int check_range(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M)
		return false;
	return true;
}

//밖의 면이라면 true return
void dfs(int row, int col) {
	if (dir)
		return;
	visited[row][col] = true;
	for (int i = 0; i < 4; i++) {
		int next_row = row + dir_x[i];
		int next_col = col + dir_y[i];

		if (!check_range(next_row, next_col)) {
			dir = true;
			return;
		}
		
		if (cheese[next_row][next_col] != 1 && !visited[next_row][next_col]) {
			dfs(next_row, next_col);
		}
	}
}

//남은 치즈가 있는지 없는지 판단.
bool check_cheese() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (cheese[i][j])
				return true;
		}
	}
	return false;
}

//겉면의 치즈 지우기
void melting_cheese() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp[i][j] = cheese[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			
			if (cheese[i][j]) {

				int count = 0;
				
				for (int k = 0; k < 4; k++) {
					int next_row = i + dir_x[k];
					int next_col = j + dir_y[k];

					if (cheese[next_row][next_col] == 0) {
						init_visited();
						dfs(next_row, next_col);
						if (dir)
							count++;
					}
					
				}

				if (count > 1) {
					tmp[i][j] = 0;
				}

			}

		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cheese[i][j] = tmp[i][j];
		}
	}
}


int main(void) {
	
	cin >> N >> M;

	int ans = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> cheese[i][j];
		}
	}

	while (check_cheese()) {

		melting_cheese();

		/*cout << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << cheese[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;*/

		ans++;
	}

	cout << ans;

	return 0;
}