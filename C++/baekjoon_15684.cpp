#include <iostream>
#include <algorithm>

using namespace std;

int ladder[300][11] = { 0 };
int N, M, H;
int ans = 987654321;

bool visited[300][11] = { 0 };

bool check_ladder() {
	for (int i = 1; i <= N; i++) {
		int col = i;
		int row = 1;

		while (row <= H) {
			if (ladder[row][col] == 1) {
				col++;
			}else if (col - 1 > 0 && ladder[row][col - 1] == 1) {
				col--;
			}
			row++;
		}

		if (col != i)
			return false;
	}
	return true;
}

void get_ans(int count, int start_row) {

	if (count < 4) {
		if (check_ladder()) {
			ans = min(ans, count);
		}
		else {
			for (int i = start_row; i <= H; i++) {
				for (int j = 1; j < N; j++) {
					if (ladder[i][j] == 0 && ladder[i][j + 1] == 0 && ladder[i][j - 1] == 0) {
						ladder[i][j] = 1;
						get_ans(count + 1, i);
						ladder[i][j] = 0;
					}
					
				}
			}
		}
	}
}

int main(void) {

	
	int buff1, buff2;
	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		cin >> buff1 >> buff2;
		ladder[buff1][buff2] = 1;
	}

	get_ans(0, 1);

	if (ans == 987654321)
		cout << -1;
	else
		cout << ans;

	return 0;
}