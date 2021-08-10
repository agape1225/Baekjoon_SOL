#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[1001];
bool visited[1001] = { 0 };

void bfs(int start) {

	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int buff = q.front();
		q.pop();

		for (int i = 0; i < graph[buff].size(); i++) {
			if (!visited[graph[buff][i]]) {
				visited[graph[buff][i]] = true;
				q.push(graph[buff][i]);
			}
		}
	}


}

int main(void) {

	int node, line;
	int buff1, buff2;
	int ans = 0;

	cin >> node >> line;

	for (int i = 0; i < line; i++) {

		cin >> buff1 >> buff2;

		graph[buff1].push_back(buff2);
		graph[buff2].push_back(buff1);

	}

	while (true) {
		int start = -1;

		for (int i = 1; i <= node; i++) {
			if (!visited[i]) {
				start = i;
				break;
			}
		}

		if (start == -1)
			break;

		bfs(start);
		ans++;
	}

	cout << ans;

	return 0;

}