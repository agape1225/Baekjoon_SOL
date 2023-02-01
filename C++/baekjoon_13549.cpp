#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int cache[100001] = { 0 };
bool visited[100001] = { 0 };
queue<pair<int, int>> q;

bool check_range(int x) {
	if (x < 0)
		return false;
	if (x > 100000)
		return false;
	return true;
}

int main(void) {

	int N, K;
	cin >> N >> K;

	visited[N] = true;
	q.push(make_pair(N, 0));

	while (!q.empty()) {
		
		int tmp;
		int num = q.front().first;
		int time = q.front().second;
		q.pop();

		tmp = num + 1;
		if (check_range(tmp)) {
			
			if (visited[tmp]) {						//방문한적 있을 때
				if (time + 1 < cache[tmp]) {
					q.push(make_pair(tmp, time + 1));
					cache[tmp] = time + 1;
				}
			}
			else {									//방문한적 없을 때
				q.push(make_pair(tmp, time + 1));
				cache[tmp] = time + 1;
				visited[tmp] = true;
			}
		}

		tmp = num - 1;
		if (check_range(tmp)) {

			if (visited[tmp]) {						//방문한적 있을 때
				if (time + 1 < cache[tmp]) {
					q.push(make_pair(tmp, time + 1));
					cache[tmp] = time + 1;
				}
			}
			else {									//방문한적 없을 때
				q.push(make_pair(tmp, time + 1));
				cache[tmp] = time + 1;
				visited[tmp] = true;
			}
		}

		tmp = num * 2;
		if (check_range(tmp)) {

			if (visited[tmp]) {						//방문한적 있을 때
				if (time < cache[tmp]) {
					q.push(make_pair(tmp, time));
					cache[tmp] = time;
				}
			}
			else {									//방문한적 없을 때
				q.push(make_pair(tmp, time));
				cache[tmp] = time;
				visited[tmp] = true;
			}
		}
	}

	cout << cache[K];

	return 0;

}