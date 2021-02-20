#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>

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

void checkField(int field[SIZE][SIZE], int row, int col) {
	queue<Point> locate;
	//stack<Point> locate;
	Point loc;
	loc.row = row;
	loc.col = col;
	locate.push(loc);
	field[row][col] = false;

	while (!locate.empty()) {

		Point current = locate.front();
		locate.pop();

		if (checkRange(current.row - 1, current.col) == true && field[current.row - 1][current.col] == 1) {
			Point buff;
			buff.row = current.row - 1;
			buff.col = current.col;
			field[current.row - 1][current.col] = 0;
			locate.push(buff);
		}

		if (checkRange(current.row + 1, current.col) == true && field[current.row + 1][current.col] == 1) {
			Point buff;
			buff.row = current.row + 1;
			buff.col = current.col;
			field[current.row + 1][current.col] = 0;
			locate.push(buff);
		}

		if (checkRange(current.row, current.col + 1) == true && field[current.row][current.col + 1] == 1) {
			Point buff;
			buff.row = current.row;
			buff.col = current.col + 1;
			field[current.row][current.col + 1] = 0;
			locate.push(buff);
		}

		if (checkRange(current.row , current.col - 1) == true && field[current.row][current.col - 1] == 1) {
			Point buff;
			buff.row = current.row;
			buff.col = current.col - 1;
			field[current.row][current.col - 1] = 0;
			locate.push(buff);
		}
	}
}

void printArr(int arr[SIZE][SIZE], int row, int col) {
	
	cout << endl;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			//cout << dec << arr[i][j] << " ";
			printf("%d ", arr[i][j]);
		}
		cout << endl;
	}

	cout << endl;
}

int main(void) {
	int T;
	int field[SIZE][SIZE];
	

	cin >> T;

	for (int i = 0; i < T; i++) {
		int row, col, num;
		int count = 0;
		cin >> row >> col >> num;

		for (int j = 0; j < row; j++) {
			for (int k = 0; k < col; k++)
				field[j][k] = -1;
		}

		for (int j = 0; j < num; j++) {
			int buffRow, buffCol;
			cin >> buffRow >> buffCol;
			field[buffRow][buffCol] = 1;
		}

		//printArr(field, row, col);

		for (int j = 0; j < row; j++) {
			for (int k = 0; k < col; k++) {
				if (field[j][k] == 1) {
					checkField(field, j, k);
					count++;
					//printArr(field, row, col);
				}
			}

		}

		cout << count << endl;

	}

	return 0;
}