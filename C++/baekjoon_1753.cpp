#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

vector<pair<int, int>> nodes[20001];
int cache[20001];

int main(void) {
	int K, V, E;
	int u, v, w;
	priority_queue<pair<int, int>> pq;

	cin >> V >> E >> K;

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		nodes[u].push_back(make_pair(v, w));
	}

	for (int i = 1; i <= V; i++) {
		cache[i] = INF;
	}

	cache[K] = 0;
	pq.push(make_pair(0, K));

	while (!pq.empty()) {
		int current_node = pq.top().second;
		int current_cost = -pq.top().first;
		pq.pop();

		for (auto it : nodes[current_node]) {
			int next_cost = cache[current_node] + it.second;
			int next_node = it.first;

			if (cache[next_node] > next_cost) {
				cache[next_node] = next_cost;
				pq.push(make_pair(-next_cost, next_node));
			}

		}
	}

	for (int i = 1; i <= V; i++) {
		if (cache[i] == INF)
			cout << "INF" << '\n';
		else
			cout << cache[i] << '\n';
	}

	return 0;
}