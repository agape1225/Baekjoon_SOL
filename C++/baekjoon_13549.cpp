#include <iostream>
#include <queue>
#include <utility>

using namespace std;

bool visited[100001] = { 0 };
int cache[100001] = { 0 };
queue < pair<int, int>> q;

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

	q.push(make_pair(N, 0));
	visited[N] = true;

	while (!q.empty()) {

		int location		= q.front().first;
		int time			= q.front().second;
		int tmp_location	= NULL;
		int tmp_time		= NULL;
		q.pop();

		tmp_location = location + 1;
		tmp_time = time + 1;
		if (check_range(tmp_location)) {
			//방문한적 있을 때
			if (visited[tmp_location]) {
				if (cache[tmp_location] > tmp_time) {
					q.push(make_pair(tmp_location, tmp_time));
					cache[tmp_location] = tmp_time;
				}
			}
			else {
				q.push(make_pair(tmp_location, tmp_time));
				cache[tmp_location] = tmp_time;
				visited[tmp_location] = true;
			}
		}

		tmp_location = location - 1;
		if (check_range(tmp_location)) {
			//방문한적 있을 때
			if (visited[tmp_location]) {
				if (cache[tmp_location] > tmp_time) {
					q.push(make_pair(tmp_location, tmp_time));
					cache[tmp_location] = tmp_time;
				}
			}
			else {
				q.push(make_pair(tmp_location, tmp_time));
				cache[tmp_location] = tmp_time;
				visited[tmp_location] = true;
			}
		}

		tmp_location = location * 2;
		tmp_time = time;
		if (check_range(tmp_location)) {
			//방문한적 있을 때
			if (visited[tmp_location]) {
				if (cache[tmp_location] > tmp_time) {
					q.push(make_pair(tmp_location, tmp_time));
					cache[tmp_location] = tmp_time;
				}
			}
			else {
				q.push(make_pair(tmp_location, tmp_time));
				cache[tmp_location] = tmp_time;
				visited[tmp_location] = true;
			}
		}

	}

	cout << cache[K];

	return 0;

}