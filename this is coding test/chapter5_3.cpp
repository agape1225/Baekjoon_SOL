#include <iostream>
#include <sstream>

#define R_MAX 4
#define C_MAX 5

using namespace std;


bool check_range(int r, int c) {

	if (r >= 0 && r < R_MAX) {

		if (c >= 0 && c < C_MAX)
			return true;
		else
			return false;
	}
	else
		return false;

}

void DFS(int icetool[4][5], int r, int c) {

	//icetool[r][c] = 1;

	//cout << -10;

	if (check_range(r - 1, c) && icetool[r - 1][c] == 0) {
		icetool[r - 1][c] = 1;
		DFS(icetool, r - 1, c);
	}
	if (check_range(r + 1, c) && icetool[r + 1][c] == 0) {
		icetool[r + 1][c] = 1;
		DFS(icetool, r + 1, c);
	}
	if (check_range(r, c - 1) && icetool[r][c - 1] == 0) {
		icetool[r][c - 1] = 1;
		DFS(icetool, r, c - 1);
	}
	if (check_range(r, c + 1) && icetool[r][c + 1] == 0) {
		icetool[r][c + 1] = 1;
		DFS(icetool, r, c + 1);
	}

}

int main(void) {

	int icetool[4][5];
	string input;
	char buff;
	int count = 0;

	
	for (int i = 0; i < 4; i++) {

		
		cin >> input;
		//cout << input << endl;

		for (int j = 0; j < 5; j++) {

			if (input[j] == '0')
				icetool[i][j] = 0;
			else
				icetool[i][j] = 1;

		}

	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			cout << icetool[i][j] << ' ';
		}
		cout << endl;
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {

			if (icetool[i][j] == 0) {
				icetool[i][j] == 1;
				count++;
				DFS(icetool, i, j);
				
			}
		}

	}

	cout << count;


	return 0;

}