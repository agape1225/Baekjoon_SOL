#include <iostream>
#include <queue>
#include <string>
#include <utility>

#define SIZE 1000
#define MAX 987654321

using namespace std;

int N, M;

int map[SIZE][SIZE];
int ans[SIZE][SIZE] = { 0 };
//bool visited[SIZE][SIZE] = { 0 };

typedef struct point {

	int x;
	int y;
	int count;
	bool is_pass;

}point;

queue<point> q;

int dir_x[4] = { 1,0,-1,0 };
int dir_y[4] = { 0,1,0,-1 };

bool check_range(int x, int y) {

	if (x < 0 || x >= N)
		return false;
	else {
		if (y < 0 || y >= M)
			return false;
		else
			return true;
	}

}

int main(void) {

	string buff;


	cin >> N >> M;

	for (int i = 0; i < N; i++) {

		cin >> buff;

		for (int j = 0; j < M; j++) {

			map[i][j] = buff[j] - '0';
			ans[i][j] = MAX;

		}

	}

	point start = { 0,0,1, false };

	q.push(start);

	while (!q.empty()) {

		point tmp = q.front();
		q.pop();

		/*if (visited[tmp.x][tmp.y]) {

			if (ans[tmp.x][tmp.y] < tmp.count) {

				continue;

			}

		}*/

		//visited[tmp.x][tmp.y] = true;


		if (ans[tmp.x][tmp.y] < tmp.count) {

			continue;

		}


		ans[tmp.x][tmp.y] = tmp.count;

		for (int i = 0; i < 4; i++) {

			int buff_x = tmp.x + dir_x[i];
			int buff_y = tmp.y + dir_y[i];

			if (check_range(buff_x, buff_y)) {

				point p_tmp;
				p_tmp.x = buff_x;
				p_tmp.y = buff_y;
				p_tmp.count = tmp.count + 1;

				if (map[buff_x][buff_y] == 1) {

					if (tmp.is_pass) {
						continue;
					}
					else {
						p_tmp.is_pass = true;
					}

				}

				q.push(p_tmp);

			}

		}


	}

	//for (int i = 0; i < N; i++) {

	//	for (int j = 0; j < M; j++) {

	//		cout << ans[i][j] << ' ';

	//	}
	//	cout << endl;
	//}

	if (ans[N - 1][M - 1] >= MAX)
		cout << -1;
	else
		cout << ans[N - 1][M - 1];

	return 0;

}