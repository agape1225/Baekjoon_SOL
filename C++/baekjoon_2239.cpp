#include <iostream>
#include <vector>

using namespace std;

vector<string> ans;
bool ans_dir = false;
bool row_cache[10][10] = { 0 };
bool col_cache[10][10] = { 0 };
int square_cache[10][10] = { 0 };


int get_start(int num) {
	if (num < 3)
		return 0;
	if (num < 6)
		return 3;
	return 6;
}

bool check_range(vector<string> sudoku, int num, int row, int col) {
	//row check

	char tmp = num + '0';

	for (int i = 0; i < 9; i++) {
		if (i == col)
			continue;
		if (sudoku[row][i] == tmp) {
			return false;
		}
	}

	//col check

	for (int i = 0; i < 9; i++) {
		if (i == row)
			continue;
		if (sudoku[i][col] == tmp) {
			return false;
		}
	}

	//square check

	int start_row = get_start(row);
	int start_col = get_start(col);

	for (int i = start_row; i < start_row + 3; i++) {
		for (int j = start_col; j < start_col + 3; j++) {
			if (i == row && j == col)
				continue;
			if (sudoku[i][j] == tmp)
				return false;
		}
	}

	return true;
}

void get_ans(vector<string> sudoku) {

	if (ans_dir)
		return;

	int dir = false;
	int row = 9;
	int col = 9;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudoku[i][j] == '0') {
				dir = true;
				row = i;
				col = j;
				break;
			}
		}
		if (dir)
			break;
	}

	if (dir) {
		for (int i = 1; i < 10; i++) {
			/*if (check_range(sudoku, i, row, col)) {
				sudoku[row][col] = i + '0';
				get_ans(sudoku);
				sudoku[row][col] = '0';
			}*/

			if (!row_cache[row][i] && !col_cache[col][i] && !square_cache[row / 3 * 3 + col / 3][i]) {
				row_cache[row][i] = true;
				col_cache[col][i] = true;
				square_cache[row / 3 * 3 + col / 3][i] = true;
				sudoku[row][col] = i + '0';
				get_ans(sudoku);
				row_cache[row][i] = false;
				col_cache[col][i] = false;
				square_cache[row / 3 * 3 + col / 3][i] = false;
				sudoku[row][col] = '0';
			}

		}
	}
	//전부 차있다는 뜻
	else {
		/*cout << "------------------------" << endl;
		for (int j = 0; j < 9; j++)
			cout << sudoku[j] << endl;
		cout << "------------------------" << endl;*/
		ans_dir = true;
		ans = sudoku;
	}
}

int main(void) {

	vector<string> sudoku;
	string tmp;

	for (int i = 0; i < 9; i++) {
		cin >> tmp;
		sudoku.push_back(tmp);
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			row_cache[i][sudoku[i][j] - '0'] = true;
			col_cache[j][sudoku[i][j] - '0'] = true;
			square_cache[i / 3 * 3 + j / 3][sudoku[i][j] - '0'] = true;
		}
	}

	//백트래킹 진행
	get_ans(sudoku);

	for (int i = 0; i < 9; i++)
		cout << ans[i] << endl;

	return 0;

}