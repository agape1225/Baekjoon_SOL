#include <iostream>
#include <queue>
#define SIZE 101

using namespace std;

typedef struct point {
	int row;
	int col;
	int dir;
} point;

int factory[SIZE][SIZE];
int visited[SIZE][SIZE] = { 0 };

int row_dir[5] = { 0, 0, 0, 1, -1 };
int col_dir[5] = { 0, 1, -1, 0, 0 };

queue<point> q;

int get_gap(int dir1, int dir2) {

	if (dir1 == dir2)
		return 0;

	if (dir1 < 3) {
		if (dir2 < 3) {
			return 2;
		}
		else
			return 1;

	}
	else {
		if (dir2 > 2)
			return 2;
		else
			return 1;
	}
}

bool check(int row, int col, int M, int N) {
	if (row < 1 || row > M)
		return false;
	else {
		if (col < 1 || col > N) {
			return false;
		}
		else {
			if (factory[row][col] == -1)
				return false;
			else
				return true;
		}
	}
}

int main(void) {

	int M, N;
	int start_row, start_col, start_dir;
	int end_row, end_col, end_dir;
	int count = 0;

	cin >> M >> N;

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> factory[i][j];
			if (factory[i][j] == 1)
				factory[i][j] = -1;
		}
	}

	cin >> start_row >> start_col >> start_dir;
	cin >> end_row >> end_col >> end_dir;

	point p;
	p.row = start_row;
	p.col = start_col;
	p.dir = start_dir;

	q.push(p);
	visited[start_row][start_col] = true;

	while (!q.empty()) {

		//cout << "------------------------------------------" << endl;

		/*for (int i = 1; i <= M; i++) {

			for (int j = 1; j <= N; j++) {
				cout.width(5);
				cout << factory[i][j] << ' ';
			}
			cout << endl;
		}*/

		/*cout << "queue_size: " << q.size() << endl;
		cout << "queue_front_1: " << q.front().row << q.front().col << endl;*/

		point buff = q.front();
		q.pop();

		//cout << "start row: " << buff.row << " end_row: " << buff.col << endl;

		for (int i = 1; i < 5; i++) {

			//int row = buff.row + row_dir[i];
			//int col = buff.col + col_dir[i];

			for (int j = 1; j < 4; j++) {

				int row = buff.row + row_dir[i] * j;
				int col = buff.col + col_dir[i] * j;

				if (check(row, col, M, N)) {

					if (visited[row][col]) {

						if (row == end_row && col == end_col) {


							if (factory[row][col] > factory[buff.row][buff.col] + get_gap(buff.dir, i) + 1 + get_gap(i, end_dir)) {

								factory[row][col] = factory[buff.row][buff.col] + get_gap(buff.dir, i) + 1 + get_gap(i, end_dir);

								//cout << "*end* input_row: " << row << " input_col: " << col << " input_size: " << factory[row][col] << endl;

							}

						}
						else {
							if (factory[row][col] > factory[buff.row][buff.col] + get_gap(buff.dir, i) + 1) {

								factory[row][col] = factory[buff.row][buff.col] + get_gap(buff.dir, i) + 1;

								point tmp;;
								tmp.row = row;
								tmp.col = col;
								tmp.dir = i;

								q.push(tmp);

								//cout << "input_row: " << row << " input_col: " << col << " input_size: " << factory[row][col] << endl;

							}
						}

					}
					else {
						if (row == end_row && col == end_col) {

							factory[row][col] = factory[buff.row][buff.col] + get_gap(buff.dir, i) + 1 + get_gap(i, end_dir);
							//cout << "*end* input_row: " << row << " input_col: " << col << " input_size: " << factory[row][col] << endl;
							visited[row][col] = true;

						}
						else {

							factory[row][col] = factory[buff.row][buff.col] + get_gap(buff.dir, i) + 1;

							point tmp;
							tmp.row = row;
							tmp.col = col;
							tmp.dir = i;

							visited[row][col] = true;
							q.push(tmp);
							//cout << "input_row: " << row << " input_col: " << col << " input_size: " << factory[row][col] << endl;
						}



					}

				}
				else {
					break;
				}

			}



		}

	}

	//cout << "------------------------------------------" << endl;

	/*for (int i = 1; i <= M; i++) {

		for (int j = 1; j <= N; j++) {
			cout.width(5);
			cout << factory[i][j] << ' ';
		}
		cout << endl;

	}*/

	cout << factory[end_row][end_col];

	return 0;

}
