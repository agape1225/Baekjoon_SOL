#include <cstdio>
#include <iostream>
#define SIZE 50

//w = 1, b = -1

using namespace std;

int main(void) {
	int bord[SIZE][SIZE];
	int row, col;

	cin >> row >> col;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			char buff;
			cin >> buff;
			if (buff == 'W')
				bord[i][j] = 1;
			else
				bord[i][j] = -1;
		}
	}

	int min = 64;

	for (int i = 0; i <= row - 8; i++) {
		for (int j = 0; j <= col - 8; j++) {

			int startW = 0;
			int startB = 0;

			for (int k = i; k < i + 8; k++) {
				for (int l = j; l < j + 8; l++) {
					if (k % 2 == l % 2) {
						if (bord[k][l] == 1)
							startB++;
						else
							startW++;
					}
					else {
						if (bord[k][l] == 1)
							startW++;
						else
							startB++;
					}
				}
			}

			int buff = startW <= startB ? startW : startB;
			if (buff < min)
				min = buff;

		}
	}

	cout << min << endl;

	return 0;

}