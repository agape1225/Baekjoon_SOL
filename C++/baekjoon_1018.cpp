#include <cstdio>
#include <iostream>
#define SIZE 50

using namespace std;

int main(void) {
	int bord[SIZE][SIZE];
	int row, col;
	int trash;

	scanf("%d %d", &row, &col);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cin >> bord[i][j];
		//scanf("%c", &trash);
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			printf("%c", bord[i][j]);
		//printf("\n");
	}

	return 0;

}