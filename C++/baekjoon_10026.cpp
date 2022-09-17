#include <iostream>
#include <string>
#include <queue>

using namespace std;

bool check_dir(int x, int y, int N) {
	if (x > -1 && x < N && y > -1 && y < N)
		return true;
	return false;
}

int solution(string arr[100], int N) {

	int count = 0;
	int count_arr = 0;
	queue<pair<int, int>> q;
	
	int standard = NULL;
	int dir_x[4] = { 0, 1, 0, -1 };
	int dir_y[4] = { 1, 0, -1, 0 };
	int dir = false;

	while (count_arr < N * N) {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] != 'N') {
					q.push(make_pair(i, j));
					standard = arr[i][j];
					arr[i][j] = 'N';
					//cout << standard << endl;
					count_arr++;
					dir = true;
					break;
				}
					
			}
			if (dir)
				break;
		}

		dir = false;

		while (!q.empty()) {
			pair<int, int> tmp = q.front();
			q.pop();

			//int buff = arr[tmp.first][tmp.second];
			// 값 세팅

			// bfs 본격 시작
			for (int i = 0; i < 4; i++) {

				int buff_x = dir_x[i] + tmp.first;
				int buff_y = dir_y[i] + tmp.second;

				if (check_dir(buff_x, buff_y, N) && arr[buff_x][buff_y] == standard) {
					q.push(make_pair(buff_x, buff_y));
					arr[buff_x][buff_y] = 'N';
					count_arr++;
				}
			}

			/*for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++)
					cout << arr[i][j] << ' ';
				cout << endl;
			}
			cout << endl;*/
		}
		//cout << ++count;
		count++;
	}
	return count;
}

int main(void) {
	
	string arr1[100];
	string arr2[100];
	string input;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		arr1[i] = arr2[i] = input;
	}

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << arr[i][j] << ' ';
		cout << endl;
	}*/

	cout << solution(arr1, N) << ' ';

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr2[i][j] == 'R')
				arr2[i][j] = 'G';
		}
	}

	cout << solution(arr2, N);

	return 0;

}
