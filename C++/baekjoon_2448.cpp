#include <iostream>

using namespace std;

char cache[4000][7000] = { 0 };

//¹Ø¹Ù´ÚÀÌ depth°³ÀÎ »ï°¢Çü Âï±â
void print_triangle(int v_row, int v_col, int N) {

	int floor_max = N / 3 * 5 + (N / 3 - 1);

	//cout << v_row << ' ' << v_col << ' ' << N << ' ' << floor_max << endl;

	if (floor_max == 5) {
		cache[v_row][v_col] = '*';
		cache[v_row + 1][v_col - 1] = '*';
		cache[v_row + 1][v_col + 1] = '*';
		cache[v_row + 1][v_col] = ' ';
		for (int i = 0; i < 5; i++)
			cache[v_row + 2][v_col - 2 + i] = '*';
	}
	else {
		print_triangle(v_row,			v_col,					N / 2);
		print_triangle(v_row + N / 2,	v_col + (((floor_max) / 4) + 1),	N / 2);
		print_triangle(v_row + N / 2,	v_col - (((floor_max) / 4) + 1),	N / 2);
	}

}

int main(void) {
	
	int N;
	cin >> N;

	//int level = 1; // Âï¾î¾ßÇÒ »ï°¢ÇüÀÇ °¹¼ö

	int row_max = N;
	int col_max = N / 3 * 5 + (N / 3 - 1);
	
	print_triangle(0, col_max / 2, N);

	for (int i = 0; i < row_max; i++) {
		for (int j = 0; j < col_max; j++) {
			if (cache[i][j] == 0)
				cout << ' ';
			else
				cout << cache[i][j];
		}
		cout << endl;
	}

	return 0;

}