#include <iostream>
#include <queue>
#include <utility>

using namespace std;

bool check_range(int i, int j, int w, int h) {
	if (i < 0 || i >= h || j < 0 || j >= w)
		return false;
	return true;
}

int dir_x[8] = {1, 0, -1, 0, 1, 1,-1, -1};
int dir_y[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };

int main(void) {
	while (true) {

		int w, h;
		cin >> w >> h;

		if (w == 0 && h == 0)
			return 0;

		int map[51][51];
		int count = 0;
		queue<pair<int, int>> q;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				
				if (map[i][j] == 1) {

					//cout << "-----------------------------------------" << endl;
					count++;

					map[i][j] = 0;
					q.push(make_pair(i, j));

					while (!q.empty()) {

						pair<int, int> top = q.front();
						q.pop();

						for (int k = 0; k < 8; k++) {

							int x = top.first + dir_x[k];
							int y = top.second + dir_y[k];

							if (check_range(x, y, w, h) && map[x][y] == 1) {
								map[x][y] = 0;
								q.push(make_pair(x, y));
							}
						}

					}

				}

			}
		}

		cout << count << endl;
	}
}