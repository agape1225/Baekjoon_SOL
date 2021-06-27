//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int white = 0;
//int blue = 0;
//
//void solution(vector<vector<int>> bord, int row, int col, int size) {
//
//	int standard = bord[row][col];
//	bool ans = true;
//
//	if (size == 1) {
//		if (standard == 0) {
//			white++;
//		}
//		else {
//			blue++;
//		}
//		return;
//	}
//
//	for (int i = 0; i < size; i++) {
//		
//		for (int j = 0; j < size; j++) {
//
//			if (standard != bord[row + i][col + j]) {
//				ans = false;
//				break;
//			}
//
//		}
//		if (!ans)
//			break;
//	}
//
//	if (ans) {
//
//		if (standard == 0)
//			white++;
//		else
//			blue++;
//
//	}
//	else {
//		int half = size / 2;
//		solution(bord, row, col, half);
//		solution(bord, row, col + half, half);
//		solution(bord, row + half, col, half);
//		solution(bord, row + half, col + half, half);
//
//	}
//
//
//}
//
//int main(void) {
//
//	
//	int size, buff;
//	int ans;
//
//	cin >> size;
//
//	vector<vector<int>> bord(size, vector<int>(size));
//
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < size; j++) {
//			
//			cin >> buff;
//			bord[i][j] = buff;
//		}
//	}
//
//
//	solution(bord, 0, 0, size);
//	
//	cout << white << endl << blue;
//
//	return 0;
//
//}

#include <iostream>

using namespace std;

int white = 0;
int blue = 0;

int bord[128][128];

void solution(int row, int col, int size) {

	int standard = bord[row][col];
	bool ans = true;

	if (size == 1) {
		if (standard == 0) {
			white++;
		}
		else {
			blue++;
		}
		return;
	}

	for (int i = 0; i < size; i++) {
		
		for (int j = 0; j < size; j++) {

			if (standard != bord[row + i][col + j]) {
				ans = false;
				break;
			}

		}
		if (!ans)
			break;
	}

	if (ans) {

		if (standard == 0)
			white++;
		else
			blue++;

	}
	else {
		int half = size / 2;
		solution(row, col, half);
		solution(row, col + half, half);
		solution(row + half, col, half);
		solution(row + half, col + half, half);

	}


}

int main(void) {

	int size;
	int buff;
	cin >> size;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> buff;
			bord[i][j] = buff;
		}
	}

	solution(0, 0, size);

	cout << white << endl << blue;

	return 0;

}