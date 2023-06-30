#include <iostream>

using namespace std;

int house[50][50] = { 0 };
int R, C, T;
int dir_x[4] = { 0, 1, 0, -1 };
int dir_y[4] = { 1, 0, -1, 0 };

void moving_right(int start_row) {
	
	int tmp[50] = { 0 };

	for (int i = 1; i < C - 1; i++) {
		tmp[i + 1] = house[start_row][i];
	}
	for (int i = 1; i < C; i++) {
		house[start_row][i] = tmp[i];
	}
}

void moving_up(int start_row, int start_col, int conditional) {
	int tmp[50] = { 0 };
	int max = 0;

	if (start_col == 0) {
		max = conditional - 1;
	}

	for (int i = start_row; i > max; i--) {
		tmp[i - 1] = house[i][start_col];
	}
	for (int i = start_row; i >= max; i--) {
		house[i][start_col] = tmp[i];
	}

}

void moving_left(int start_row, int start_col) {
	int tmp[50] = { 0 };
	for (int i = start_col; i > 0; i--) {
		tmp[i - 1] = house[start_row][i];
	}
	for (int i = start_col; i >= 0; i--) {
		house[start_row][i] = tmp[i];
	}
}

void moving_down(int start_row, int start_col, int conditional) {
	int tmp[50] = { 0 };
	int max = R;

	if (start_row == 0) {
		max = conditional;
	}


	for (int i = start_row; i < max - 1; i++) {
		tmp[i + 1] = house[i][start_col];
	}
	for (int i = start_row; i < max; i++) {
		house[i][start_col] = tmp[i];
	}

}

bool check_range(int r, int c) {
	if (r < 0 || r >= R || 
		c < 0 || c >= C)
		return false;
	return true;
}

void diffusion() {
	int tmp[50][50] = { 0 };

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {

			if (house[i][j] == -1)
				tmp[i][j] = -1;

			else if (house[i][j] > 0) {

				int count = 0;

				for (int k = 0; k < 4; k++) {
					
					int tmp_row = i + dir_x[k];
					int tmp_col = j + dir_y[k];

					if (check_range(tmp_row, tmp_col) && 
						house[tmp_row][tmp_col] != -1) {

						count++;
						tmp[tmp_row][tmp_col] += house[i][j] / 5;
					}
				}
				tmp[i][j] += house[i][j] - ((house[i][j] / 5) * count);
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			house[i][j] = tmp[i][j];
		}
	}

}

void air_cleaner() {

	int up_row, down_row;

	//시작 위치 구하기
	for (int i = 0; i < R; i++) {
		if (house[i][0] == -1) {
			up_row = i;
			down_row = i + 1;
			break;
		}
	}

	//위쪽 공기 청정기 left -> up -> right -> down 순으로 전부 시작 number
	moving_down(0, 0, up_row);
	moving_left(0, C - 1);
	moving_up(up_row, C - 1, 0);
	moving_right(up_row);

	//아래쪽 공기 청정기
	moving_up(R - 1, 0, down_row);
	moving_left(R - 1, C - 1);
	moving_down(down_row, C - 1, up_row);
	moving_right(down_row);

	house[up_row][0] = -1;
	house[down_row][0] = -1;

}

int get_fine_dust() {

	int count = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if(house[i][j] != -1)
				count += house[i][j];
		}
	}
	return count;

}

int main(void) {

	cin >> R >> C >> T;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> house[i][j];
		}
	}

	for (int i = 0; i < T; i++) {
		diffusion();

		/*cout << endl << endl;

		for (int k = 0; k < R; k++) {
			for (int j = 0; j < C; j++) {
				cout << house[k][j] << ' ';
			}
			cout << endl;
		}*/

		air_cleaner();
		
		/*cout << endl << endl;

		for (int k = 0; k < R; k++) {
			for (int j = 0; j < C; j++) {
				cout << house[k][j] << ' ';
			}
			cout << endl;
		}*/
		
		
	}

	cout << get_fine_dust();

	return 0;

}