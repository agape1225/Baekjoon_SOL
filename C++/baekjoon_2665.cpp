#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

#define SIZE 50
#define MAX 2501

using namespace std;

typedef struct data {
	int x;
	int y;
	int block;
} data, Data;

int n;

int dir_x[4] = { -1, 0, 1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };

bool check_range(int x, int y) {

	if (x < 0 || x >= n)
		return false;
	else {
		if (y < 0 || y >= n)
			return false;
		else
			return true;
	}

}

int main(void) {

	int bord[SIZE][SIZE];
	
	bool visited[SIZE][SIZE] = { 0 };
	int cost[SIZE][SIZE];

	string input;
	queue<Data> q;

	cin >> n;

	for (int i = 0; i < n; i++) {

		cin >> input;

		for (int j = 0; j < n; j++) {
			bord[i][j] = input[j] - '0';
			//cost[i][j] = MAX;
		}

	}

	Data start;
	start.x = 0;
	start.y = 0;
	start.block = 0;

	q.push(start);
	//visited[0][0] = true;


	while (!q.empty()) {

		//cout << 1;
		
		Data buff = q.front();
		q.pop();
		bool dir = true;

		if (visited[buff.x][buff.y]) {

			if (cost[buff.x][buff.y] > buff.block)
				cost[buff.x][buff.y] = buff.block;
			else
				dir = false;

		}
		else {
			visited[buff.x][buff.y] = true;
			cost[buff.x][buff.y] = buff.block;
		}
		
		if (dir) {

			for (int i = 0; i < 4; i++) {

				int buff_x = buff.x + dir_x[i];
				int buff_y = buff.y + dir_y[i];
				int buff_block = buff.block;

				if (check_range(buff_x, buff_y)) {

					if (bord[buff_x][buff_y] == 0) {
						buff_block++;
					}

					Data tmp;
					tmp.x = buff_x;
					tmp.y = buff_y;
					tmp.block = buff_block;

					q.push(tmp);

				}

			}

		}
	}

	/*for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			cout << cost[i][j] << ' ';

		}

		cout << endl;

	}*/

	cout << cost[n - 1][n - 1];

	return 0;

}