#include <iostream>
#include <queue>

#define SIZE 50

using namespace std;

typedef struct Point {
	int row;
	int col;
} Point;

bool checkRange(int row, int col) {
	if ((row > -1 && row < 50) && (col > -1 && col < 50))
		return true;
	else
		return false;
}

void checkField(bool field[SIZE][SIZE], int row, int col) {
	queue<Point> locate;
	Point loc;
	loc.row = row;
	loc.col = col;
	locate.push(loc);

	while (!locate.empty()) {

		Point current = locate.front();
		locate.pop();

		field[current.row][current.col] = false;

		if (checkRange(current.row - 1, current.col) && field[current.row - 1][current.col] == true) {
			Point buff;
			buff.row = current.row - 1;
			buff.col = current.col;
			locate.push(buff);
		}

		if (checkRange(current.row + 1, current.col) && field[current.row + 1][current.col] == true) {
			Point buff;
			buff.row = current.row + 1;
			buff.col = current.col;
			locate.push(buff);
		}

		if (checkRange(current.row, current.col + 1) && field[current.row][current.col + 1] == true) {
			Point buff;
			buff.row = current.row;
			buff.col = current.col + 1;
			locate.push(buff);
		}

		if (checkRange(current.row , current.col - 1) && field[current.row][current.col - 1] == true) {
			Point buff;
			buff.row = current.row;
			buff.col = current.col - 1;
			locate.push(buff);
		}


	}

}

int main(void) {
	int T;
	bool field[SIZE][SIZE];
	

	cin >> T;

	for (int i = 0; i < T; i++) {
		int row, col, num;
		int count = 0;
		cin >> row >> col >> num;

		for (int j = 0; j < row; j++) {
			for (int k = 0; k < col; k++)
				field[SIZE][SIZE] = false;
		}

		for (int j = 0; j < num; j++) {
			int buffRow, buffCol;
			cin >> buffRow >> buffCol;
			field[buffRow][buffCol] = true;
		}

		for (int j = 0; j < row; j++) {
			for (int k = 0; k < col; k++) {
				if (field[j][k] == true) {
					checkField(field, j, k);
					count++;
				}
			}
		}

		cout << count << endl;

	}

	return 0;
}