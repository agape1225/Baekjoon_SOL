#include <iostream>
#include <algorithm>

using namespace std;

int bord[20][20] = { 0 };
int N;
int ans = -1;

void control_bord(int dir) {
	bool visited[20][20] = { 0 };
	if (dir == 0) {				//up
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < N; j++) {

				//find end
				int row = i - 1;
				int col = j;

				while (row > 0 && bord[row][col] == 0) {
					row--;
				}

				if (bord[row][col] != 0) {

					if (bord[i][j] == bord[row][col] && !visited[row][col]) {
						bord[row][col] *= 2;
						bord[i][j] = 0;
						visited[row][col] = true;
					}
					else {
						if (i != row + 1) {
							bord[row + 1][col] = bord[i][j];
							bord[i][j] = 0;
						}
					}
				}
				else {
					bord[row][col] = bord[i][j];
					bord[i][j] = 0;
				}
			}
		}

	}
	else if (dir == 1) {		//down

		for (int i = N - 2; i >= 0; i--) {
			for (int j = 0; j < N; j++) {


				//find end
				int row = i + 1;
				int col = j;

				while (row < N - 1 && bord[row][col] == 0) {
					row++;
				}

				if (bord[row][col] != 0) {

					if (bord[i][j] == bord[row][col] && !visited[row][col]) {
						bord[row][col] *= 2;
						bord[i][j] = 0;
						visited[row][col] = true;
					}
					else {

						if (i != row - 1) {
							bord[row - 1][col] = bord[i][j];
							bord[i][j] = 0;
						}
						
					}
				}
				else {
					bord[row][col] = bord[i][j];
					bord[i][j] = 0;
				}
			}
		}

	}
	else if (dir == 2) {		//left
		for (int j = 1; j < N; j++) {
			for (int i = 0; i < N; i++) {


				//find end
				int row = i;
				int col = j - 1;

				while (col > 0 && bord[row][col] == 0) {
					col--;
				}

				if (bord[row][col] != 0) {

					if (bord[i][j] == bord[row][col] && !visited[row][col]) {
						bord[row][col] *= 2;
						bord[i][j] = 0;
						visited[row][col] = true;
					}
					else {

						if (j != col + 1) {
							bord[row][col + 1] = bord[i][j];
							bord[i][j] = 0;
						}

					}
				}
				else {
					bord[row][col] = bord[i][j];
					bord[i][j] = 0;
				}
			}
		}
	}
	else {						//right

	for (int j = N - 2; j > -1; j--) {
		for (int i = 0; i < N; i++) {


			//find end
			int row = i;
			int col = j + 1;

			while (col < N - 1 && bord[row][col] == 0) {
				col++;
			}

			if (bord[row][col] != 0) {

				if (bord[i][j] == bord[row][col] && !visited[row][col]) {
					bord[row][col] *= 2;
					bord[i][j] = 0;
					visited[row][col] = true;
				}
				else {

					if (j != col - 1) {
						bord[row][col - 1] = bord[i][j];
						bord[i][j] = 0;
					}

				}
			}
			else {
				bord[row][col] = bord[i][j];
				bord[i][j] = 0;
			}
		}
	}

	}
}

void sol(int count) {
	if (count < 5) {

		int bord_buff[20][20];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				bord_buff[i][j] = bord[i][j];
			}
		}
		for (int k = 0; k < 4; k++) {
			/*cout << count << endl << endl;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					cout << bord[i][j] << ' ';
				}
				cout << endl;
			}*/
			control_bord(k);
			sol(count + 1);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					bord[i][j] = bord_buff[i][j];
				}
			}
		}
		
	}
	else {
		int max_num = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				max_num = max(max_num, bord[i][j]);
			}
		}
		ans = max(max_num, ans);
	}
}


int main(void) {

	int bord_buff[20][20] = { 0 };

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> bord[i][j];
			bord_buff[i][j] = bord[i][j];
		}
	}

	sol(0);

	/*for (int k = 0; k < 4; k++) {
		
		control_bord(k);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << bord[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				bord[i][j] = bord_buff[i][j];
			}
		}

	}*/

	cout << ans;

	return 0;


}