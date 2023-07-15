#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int degree[32001] = { 0 };
vector<int> graph[32001];

int main(void) {
	
	int N, M;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;

		degree[B]++;
		graph[A].push_back(B);
	}

	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node << ' ';

		for (int i = 0; i < graph[node].size(); i++) {
			int next_node = graph[node][i];
			degree[next_node]--;

			if (degree[next_node] == 0) {
				q.push(next_node);
			}
		}
	}

	return 0;

}