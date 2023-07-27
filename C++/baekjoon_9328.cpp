#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dir_x[4] = { 0, 1, 0, -1 };
int dir_y[4] = { 1, 0, -1, 0 };

bool check_range(int row, int col, int h, int w, vector<char> map[105], bool key[26]) {
	if (row < 0 || row >= h + 2 || col < 0 || col >= w + 2 || map[row][col] == '*')
		return false;

	if ('A' <= map[row][col] && map[row][col] <= 'Z') {
		return key[map[row][col] - 'A'];
	}

	return true;
}


int main(void) {

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int h, w;
		bool key[26] = { 0 };
		queue<pair<int, int>> q;
		int count = 0;
		
		//일단 함 해보자!
		//입력 먼저

		vector<char> map[105];
		string tmp;

		//입력 부분

		cin >> h >> w;

		for (int i = 0; i < w + 2; i++) {
			map[0].push_back('.');
		}
		
		for (int i = 0; i < h; i++) {
			cin >> tmp;

			map[i + 1].push_back('.');

			for (auto it : tmp) {
				map[i + 1].push_back(it);
			}

			map[i + 1].push_back('.');

		}

		for (int i = 0; i < w + 2; i++) {
			map[h + 1].push_back('.');
		}

		cin >> tmp;

		if (tmp != "0") {
			for (auto i : tmp) {
				key[i - 'a'] = true;
			}
		}
		
		//check code
		/*for (int i = 0; i < h + 2; i++) {
			for (int j = 0; j < w + 2; j++) {
				cout << map[i][j] << ' ';
			}
			cout << endl;
		}

		for (int i = 0; i < 26; i++) {
			cout << key[i] << ' ';
		}
		cout << endl;*/

		//변경사항을 먼저 검색해야할듯
		bool dir;
		int index = 0;

		do {

			int visited[105][105] = { 0 };
			dir = false;
			
			q.push(make_pair(0, 0));
			visited[0][0] = true;
			
			while (!q.empty()) {

				int row = q.front().first;
				int col = q.front().second;
				q.pop();

				//체크
				if (map[row][col] == '$') {
					count++;
					map[row][col] = '.';
					//cout << row << ' ' << col << ' ' << count << endl;
				}
				else if ('a' <= map[row][col] && map[row][col] <= 'z') {
					key[map[row][col] - 'a'] = true;
					map[row][col] = '.';
					//cout << row << ' ' << col << ' ' << map[row][col] << endl;
					dir = true;
				}

				//탐색
				for (int i = 0; i < 4; i++) {
					
					int next_row = row + dir_x[i];
					int next_col = col + dir_y[i];

					if (check_range(next_row, next_col, h, w, map, key) && !visited[next_row][next_col]) {
						visited[next_row][next_col] = true;
						q.push(make_pair(next_row, next_col));
					}
				}
			}

			/*cout << count << ' ' << index++ << endl;
			for (int i = 0; i < 26; i++) {
				cout << key[i] << ' ';
			}
			cout << endl;*/

		} while (dir);

		cout << count << endl;
	}

	return 0;
}