#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int bord[1024][1024];

int sol(int N) {
	if (N == 2) {
		vector<int> buff = { bord[0][0], bord[1][0], bord[0][1], bord[1][1] };

		sort(buff.begin(), buff.end());

		return buff[2];
	}
	else {

		for (int i = 0; i < N; i += 2) {
			for (int j = 0; j < N; j += 2) {

				vector<int> buff = {bord[i][j], bord[i + 1][j], bord[i][j + 1], bord[i + 1][j + 1]};

				sort(buff.begin(), buff.end());

				int row = i / 2;
				int col = j / 2;

				bord[row][col] = buff[2];
			}
		}

		return sol(N / 2);

	}
}

int main(void) {

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> bord[i][j];
		}
	}

	cout << sol(N);

	return 0;

}