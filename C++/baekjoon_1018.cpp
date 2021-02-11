#include <cstdio>
#include <iostream>
#define SIZE 50

//w = 1, b = -1

using namespace std;

int main(void) {
	int bord[SIZE][SIZE];
	int weightR[SIZE] = { 0 };
	int weightC[SIZE] = { 0 };
	int row, col;
	int trash;

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

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			weightR[i] += bord[i][j];
			weightC[j] += bord[i][j];
		}
	}

	int minR = 0;
	int minC = 0;
	int min = 1000;

	for (int i = 0; i <= row - 8; i++) {
		int buff = 0;
		for (int j = i; j < i + 8; j++) {
			if (weightR[i] >= 0)
				buff += weightR[j];
			else
				buff -= weightR[j];
		}
		if (buff < min) {
			min = buff;
			minR = i;
		}
	}

	min = 1000;

	for (int i = 0; i <= col - 8; i++) {
		int buff = 0;
		for (int j = i; j < i + 8; j++) {
			if (weightC[i] >= 0)
				buff += weightC[j];
			else
				buff -= weightC[j];
		}
		if (buff < min) {
			min = buff;
			minC = i;
		}
	}

	for (int i = minR; i < minR + 8; i++) {
		for (int j = minC; j < minC + 8; j++) {

		}
	}

	return 0;

}