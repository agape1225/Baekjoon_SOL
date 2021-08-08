#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef struct point {
	int row;
	int col;
	int count;
} point;

vector<int> fac[1000];
bool visited[1000][1000] = { false };
int row, col;
int buff;
int r, c;
int dir_row[4] = { 1, 0, -1, 0 };
int dir_col[4] = { 0, 1, 0, -1 };
int ans = 0;
queue<point> q;

bool check_range(int r, int c) {

	if (visited[r][c])
		return false;

	if (r < 0 || r >= row) {
		//cout << r << ' ' << c << endl;
		return false;
	}
	else {

		if (c < 0 || c >= col) {
			//cout << r << ' ' << c << endl;
			return false;
		}
			
		else
			return true;

	}
}

void find_tomato() {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {

			if (fac[i][j] == 1) {
				point buff;

				visited[i][j] = true;

				buff.row = i;
				buff.col = j;
				buff.count = 0;

				q.push(buff);
			}

		}
	}
}

bool is_full() {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (fac[i][j] == 0)
				return false;
		}
	}
	return true;

}

int main(void) {

	
	cin >> col >> row;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			
			cin >> buff;
			fac[i].push_back(buff);

		}
	}

	/*for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << fac[i][j] << ' ';
		}
		cout << endl;
	}*/

	find_tomato();
	/*point buff;
	buff.row = r;
	buff.col = c;
	buff.count = 0;
	q.push(buff);*/

	//visited[r][c] = true;

	//cout << endl;

	while (!q.empty()) {

		//cout << "--------------------------------" << endl << endl;

		/*for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << visited[i][j] << ' ';
			}
			cout << endl;
		}*/

		//cout << endl;

		point buff = q.front();
		q.pop();
		
		if (ans < buff.count)
			ans = buff.count;

		//cout << buff.row << ' ' << buff.col << endl;

		for (int i = 0; i < 4; i++) {

			//cout << "예비: " << buff.row + dir_row[i] << ' ' << buff.col + dir_col[i] << endl;

			if (check_range(buff.row + dir_row[i], buff.col + dir_col[i]) && fac[buff.row + dir_row[i]][buff.col + dir_col[i]] != -1) {

				point tmp;
				tmp.row = buff.row + dir_row[i];
				tmp.col = buff.col + dir_col[i];
				visited[buff.row + dir_row[i]][buff.col + dir_col[i]] = true;
				tmp.count = buff.count + 1;
				fac[tmp.row][tmp.col] = buff.count + 1;
				q.push(tmp);

				//cout << "결정: " <<  tmp.row << ' ' << tmp.col << endl;

			}

		}

	}

	/*for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {

			cout << fac[i][j] << ' ';

		}

		cout << endl;
	}

	cout << endl;*/

	if (is_full())
		cout << ans;
	else	
		cout << -1;

	return 0;

}