#include <iostream>
#include <string>
#include <utility>
#include <set>
#include <queue>

using namespace std;

bool is_range(int r, int c, int max_row, int max_col) {
	if (r < 0 || r >= max_row)
		return false;
	if (c < 0 || c >= max_col)
		return false;
	return true;
}

int x_dir[4] = { 1, 0, -1, 0 };
int y_dir[4] = { 0, 1, 0, -1 };

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {

		int R, C;
		string destination[20];
		queue<pair<int, pair<int, set<char>>>> q;
		int ans = -1;
		
		cin >> R >> C;
		for (int i = 0; i < R; i++) {
			cin >> destination[i];
		}

		set<char> buffS;
		buffS.insert(destination[0][0]);
		q.push(
			make_pair(0, 
				make_pair(0, buffS)
			)
		);

		while (!q.empty()) {

			int row = q.front().first;
			int col = q.front().second.first;
			set<char> route = q.front().second.second;
			q.pop();
			int buff_size = route.size();
			if (ans < buff_size) {
				ans = buff_size;
			}


			for (int i = 0; i < 4; i++) {

				int buff_row = row + x_dir[i];
				int buff_col = col + y_dir[i];

				if (is_range(buff_row, buff_col, R, C)) {

					if (route.find(destination[buff_row][buff_col]) != route.end()) {			//있었던 경우
						
						/*int buff_size = route.size();
						if (ans < buff_size) {
							ans = buff_size;
						}*/
					}
					else {																		//없는 경우

						set<char> buffRoute(route);
						buffRoute.insert(destination[buff_row][buff_col]);
						/*cout << endl << buff_row << ',' << buff_col << ':';
						for (auto it = buffRoute.begin(); it != buffRoute.end(); it++) {
							cout << *it << ' ';
						}*/
						q.push(make_pair(buff_row, make_pair(buff_col, buffRoute)));

					}

				}

			}
		}
		cout << '#' <<  t + 1 << ' ' << ans << endl;
	}

	return 0;
}