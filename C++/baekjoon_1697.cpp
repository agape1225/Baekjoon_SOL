#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

#define MAX 100001

using namespace std;

bool visited[MAX] = { 0 };

int main(void) {

	int N, K;
	queue<pair<int,int>> q;

	cin >> N >> K;

	q.push({ N, 0 });
	visited[N] = true;

	while (!q.empty()) {
		
		pair<int, int> buff = q.front();
		q.pop();

		if (buff.first == K) {

			cout << buff.second;
			return 0;

		}

		if (buff.first * 2 <= MAX && !visited[buff.first * 2]) {
			visited[buff.first * 2] = true;
			q.push({ buff.first * 2, buff.second + 1 });
		}
		if (buff.first + 1 < MAX && !visited[buff.first + 1]) {
			visited[buff.first + 1] = true;
			q.push({ buff.first + 1, buff.second + 1 });
		}
		if (buff.first - 1 < MAX && !visited[buff.first - 1]) {
			visited[buff.first - 1] = true;
			q.push({ buff.first - 1, buff.second + 1 });
		}
	}

	return 0;

}