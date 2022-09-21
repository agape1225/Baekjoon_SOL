#include <iostream>
#include <queue>

using namespace std;

int N, M;

int ladder[2][15];
int snake[2][15];

int get_dir(int location) {

	for (int i = 0; i < N; i++) {
		if (ladder[0][i] == location)
			return ladder[1][i];
	}

	for (int i = 0; i < M; i++) {
		if (snake[0][i] == location)
			return snake[1][i];
	}

	return location;

}

int main(void) {

	int cache[101] = { 0 };
	bool visit[101] = { 0 };
	queue<pair<int, int>> q;

	int buff1, buff2;

	cin >> N >> M;

	//입력 처리
	for (int i = 0; i < N; i++) {
		cin >> buff1 >> buff2;
		
		ladder[0][i] = buff1;
		ladder[1][i] = buff2;
	}
	for (int i = 0; i < M; i++) {
		cin >> buff1 >> buff2;

		snake[0][i] = buff1;
		snake[1][i] = buff2;

	}

	//cache 처리
	/*for (int i = 0; i < 101; i++) {
		cache[i] = 987654321;
	}*/

	q.push(make_pair(get_dir(1),0));
	cache[get_dir(1)] = 0;
	visit[get_dir(1)] = true;

	while (!q.empty()) {

		/*for (auto it = q.front(); it != q.back(); it++) {
			cout << (*it).first << ' ' << (*it).end;
		}*/

		pair<int, int> top = q.front();
		q.pop();
		int location = top.first;
		int count = top.second;

		//cout << endl << "location: " << location << " count: " << count << endl;

		//주사위
		for (int i = 1; i < 7; i++) {

			int buff = location + i;
			int dir = get_dir(buff);
			if (dir <= 100) {

				

				if (visit[dir] == 0) {
					q.push(make_pair(dir, count + 1));
					//cout << buff << ' ' << count + 1 << endl;
					cache[dir] = count + 1;
					visit[dir] = true;
				}
				else {
					if (cache[dir] > count + 1) {
						
						/*cout << "It works!" << endl;
						cout << buff << ' ' << count + 1 << endl;*/
						q.push(make_pair(dir, count + 1));
						cache[dir] = count + 1;
					}
				}
			}
		}
	}

	/*for (int i = 1; i < 101; i++) {
		cout << cache[i] << endl;
	}*/

	cout << cache[100];

	return 0;

}
