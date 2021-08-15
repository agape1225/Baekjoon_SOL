#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

vector<int> maze[200];
vector<bool> visited[200];
stack<pair<int, int>> s;

bool check_range(int r, int c, int r_max, int c_max) {

	if (r < 0 || r >= r_max)
		return false;
	else {
		if (c < 0 || c >= c_max) {
			return false;
		}
		else {
			return true;
		}
	}

}

int main(void) {



	int dir_row[4] = { 1, 0, - 1, 0 };
	int dir_col[4] = { 0, 1, 0, -1 };

	int N, M;
	string input;
	int start_num, end_num;

	start_num = end_num = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < M; j++) {

			maze[i].push_back(input[j] - '0');

		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			visited[i].push_back(false);
	}

	//int buff[2] = { start_num, end_num };
	s.push(make_pair(start_num, end_num));
	
	

	while (!s.empty()) {

		bool dir = false;
		pair<int, int> tmp = s.top();
		//if (!visited[tmp.first][tmp.second]) {
		//	visited[tmp.first][tmp.second] = true;
		//	//cout << tmp.first << ' ' << tmp.second << endl;
		//}
		

		for (int i = 0; i < 4; i++) {
			int r = tmp.first + dir_row[i];
			int c = tmp.second + dir_col[i];
			if (check_range(r, c, N ,M)  && maze[r][c] != 0) {
				


				if (visited[r][c]) {
					if (maze[r][c] > maze[tmp.first][tmp.second] + 1)
						maze[r][c] = maze[tmp.first][tmp.second] + 1;
					else
						continue;
				}
				else {
					maze[r][c] = maze[tmp.first][tmp.second] + 1;
					visited[r][c] = true;
					
				}

				//cout << 1 << endl << endl;
				dir = true;
				s.push(make_pair(r, c));
				break;
			}
		}

		if(!dir)
			s.pop();

	}

	
	
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {
			cout.width(5);
			cout << maze[i][j] << ' ';
		}
		cout << endl;

	}

	return 0;

}