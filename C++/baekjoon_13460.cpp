#include <iostream>
#include <queue>

using namespace std;

typedef vector<string> BORD;

int N, M;

queue<pair<vector<string>, int>> q;


void print_bord(BORD bord) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << bord[i][j] << ' ';
		}
		cout << endl;
	}
}

void move_dir(BORD &bord, int dir) {

	int is_in = false;

	//상
	if (dir == 0) {
		//우선순위
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (bord[i][j] == 'B' || bord[i][j] == 'R') {
					int tmp_row = i;

					while (true) {
						if (bord[tmp_row - 1][j] == '.' && tmp_row - 1 >= 0) {
							tmp_row--;
						}
						else if (bord[tmp_row - 1][j] == 'O') {
							bord[i][j] = '.';
							break;
						}
						else
							break;
					}

					if (tmp_row != i) {
						bord[tmp_row][j] = bord[i][j];
						bord[i][j] = '.';
					}
				}
			}
		}

		//print_bord(bord);

	}
	//하
	else if (dir == 1) {
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < M; j++) {
				if (bord[i][j] == 'B' || bord[i][j] == 'R') {
					int tmp_row = i;

					while (true) {
						if (bord[tmp_row + 1][j] == '.' && tmp_row + 1 < N) {
							tmp_row++;
						}
						else if (bord[tmp_row + 1][j] == 'O') {
							bord[i][j] = '.';
							break;
						}
						else
							break;
					}

					if (tmp_row != i) {
						bord[tmp_row][j] = bord[i][j];
						bord[i][j] = '.';
					}
				}
			}
		}

	}
	//좌
	else if (dir == 2) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (bord[i][j] == 'B' || bord[i][j] == 'R') {
					int tmp_col = j;

					while (true) {
						if (bord[i][tmp_col - 1] == '.' && tmp_col - 1 >= 0) {
							tmp_col--;
						}
						else if (bord[i][tmp_col - 1] == 'O') {
							bord[i][j] = '.';
							break;
						}
						else
							break;
					}

					if (tmp_col != j) {
						bord[i][tmp_col] = bord[i][j];
						bord[i][j] = '.';
					}
				}
			}
		}
	}
	//우
	else {
		for (int i = 0; i < N; i++) {
			for (int j = M - 1; j >= 0; j--) {
				if (bord[i][j] == 'B' || bord[i][j] == 'R') {
					int tmp_col = j;

					while (true) {
						if (bord[i][tmp_col + 1] == '.' && tmp_col + 1 < M) {
							tmp_col++;
						}
						else if (bord[i][tmp_col + 1] == 'O') {
							bord[i][j] = '.';
							break;
						}
						else
							break;
					}

					if (tmp_col != j) {
						bord[i][tmp_col] = bord[i][j];
						bord[i][j] = '.';
					}
				}
			}
		}
	}
	//return false;
}

int main(void) {
	
	cin >> N >> M;
	string buff;
	vector<string> input;
	//BORD input = { 0 };

	for (int i = 0; i < N; i++) {
		cin >> buff;
		input.push_back(buff);
		/*for (int j = 0; j < M; j++) {
			input[i][j] = buff[j];
		}*/
	}

	q.push(make_pair(input, 0));

	while (!q.empty()) {
		BORD buff;
		BORD bord = q.front().first;
		int count = q.front().second;
		int red_row;
		int red_col;
		int blue_row;
		int blue_col;
		q.pop();

		if (count > 9)
			continue;
		//연산

		//위치 찾기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (bord[i][j] == 'R') {
					red_row = i;
					red_col = j;
				}
				if (bord[i][j] == 'B') {
					blue_row = i;
					blue_col = j;
				}
			}
		}

		for (int k = 0; k < 4; k++) {
			/*for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++)
					buff[i][j] = bord[i][j];

			}*/
			buff = bord;

			move_dir(buff, k);

			int count_b = 0;
			int count_r = 0;

			/*cout << endl;
			print_bord(buff);
			cout << endl;
			*/
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (buff[i][j] == 'B')
						count_b++;
					if (buff[i][j] == 'R')
						count_r++;
				}
			}
			if (count_b == 1 && count_r == 0) {
				//cout << k << ' ' << count + 1;
				cout << count + 1;
				return 0;
			}

			/*cout << endl << count << endl;
			print_bord(buff);
			cout << endl;*/

			if(buff != bord)
				q.push(make_pair(buff, count + 1));
		}
	}

	cout << -1;
	
	return 0;

}