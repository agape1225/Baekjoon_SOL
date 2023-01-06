#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

//구현 브루트포스

int N;
int arr[20][20];
int dir_x[4] = { -1, 0, 0, 1 };
int dir_y[4] = { 0, -1, 1, 0 };
int exp_count = 0;
int level = 2;
int ans_time = 0;

bool compare(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2) {
	if (p1.second.second == p2.second.second) {
		if (p1.first == p2.first)
			return p1.second.first < p2.second.first;
		return p1.first < p2.first;
	}
	return p1.second.second < p2.second.second;
}

bool is_range(int row, int col) {
	if (row < 0 || row >= N)
		return false;
	if (col < 0 || col >= N)
		return false;
	return true;
}

pair<int,int> bfs(int start_row, int start_col) {

	bool visited[20][20] = { 0 };
	bool is_ate = false;
	queue<pair<int, pair<int,int>>> q;
	vector <pair<int, pair<int, int>>> ans;
	q.push(make_pair(start_row, make_pair(start_col, 0)));
	visited[start_row][start_col] = true;


	while (!q.empty()) {

		int row = q.front().first;
		int col = q.front().second.first;
		int time = q.front().second.second;
		int buff_row = NULL;
		int buff_col = NULL;
		q.pop();

		for (int i = 0; i < 4; i++) {
			
			buff_row = row + dir_x[i];
			buff_col = col + dir_y[i];

			if (is_range(buff_row, buff_col) && !visited[buff_row][buff_col]) {

				if (arr[buff_row][buff_col] == 0) {
					visited[buff_row][buff_col] = true;
					q.push(make_pair(buff_row, make_pair(buff_col, time + 1)));
				}
				else {
					if (level > arr[buff_row][buff_col]) {
						is_ate = true;
						//arr[buff_row][buff_col] = 0;
						//ans_time += (time + 1);
						visited[buff_row][buff_col] = true;
						/*cout << ans_time << '-';
						cout << buff_row << ' ' << buff_col << endl << endl;*/
						q.push(make_pair(buff_row, make_pair(buff_col, time + 1)));
						ans.push_back(make_pair(buff_row, make_pair(buff_col, time + 1)));
						//return make_pair(buff_row, buff_col);
					}
					else if (level == arr[buff_row][buff_col]) {
						visited[buff_row][buff_col] = true;
						q.push(make_pair(buff_row, make_pair(buff_col, time + 1)));
					}
				}
			}
		}


		/*cout << endl << endl;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << visited[i][j] << ' ';
			}
			cout << endl;
		}*/
		
	}

	sort(ans.begin(), ans.end(), compare);
	
	/*for (auto it = ans.begin(); it != ans.end(); it++) {
		cout << endl << (*it).first << ' ' << (*it).second.first << ' ' << (*it).second.second;
	}*/

	if (is_ate) {
		exp_count++;;
		if (exp_count == level) {
			level++;
			exp_count = 0;
		}
		ans_time += ans[0].second.second;
		arr[ans[0].first][ans[0].second.first] = 0;
		return make_pair(ans[0].first, ans[0].second.first);
	}
	else
		return make_pair(-1, -1);
}

int main(void) {

	int start_row = NULL;
	int start_col = NULL;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				start_row = i;
				start_col = j;
				arr[i][j] = 0;
			}
		}
	}

	//start bfs

	pair<int, int> result = bfs(start_row, start_col);
	//cout << endl << result.first << ' ' << result.second << endl;
	while (result.first != -1 && result.second != -1) {
		//arr[result.first][result.second] = 0;
		result = bfs(result.first, result.second);
		//cout << endl << result.first << ' ' << result.second << endl;
	}

	/*if (level == 2 && exp_count == 0) {
		cout << 0;
	}
	else {

	}*/

	cout << ans_time;

	return 0;

}