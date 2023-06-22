#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

vector<pair<int, int>> graph[1005];
int dis[1005];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start, 0));
	dis[start] = 0;

	while (!pq.empty()) {
		int current = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();

		if (dis[current] < distance)
			continue;

		for (int i = 0; i < graph[current].size(); i++) {

			int next = graph[current][i].first;
			int next_dis = distance + graph[current][i].second;

			if (next_dis < dis[next]) {
				dis[next] = next_dis;
				pq.push(make_pair(next, -next_dis));
			}
		}
	}
}

void reset_dis(int max) {
	for (int i = 1; i <= max; i++) {
		dis[i] = 9876543210;
	}
}

int main(void) {

	int N, M, X;
	int ans = -1;

	cin >> N >> M >> X;

	for (int i = 0; i < M; i++) {
		int start_node, end_node, weight;
		cin >> start_node >> end_node >> weight;
		graph[start_node].push_back(make_pair(end_node, weight));
		//dis[i + 1] = 101;
	}

	int dis_ans[1005] = { 0 };

	for (int i = 1; i <= N; i++) {

		if (i == X)
			continue;

		reset_dis(N);
		dijkstra(i);
		dis_ans[i] = dis[X];
	}

	reset_dis(N);
	dijkstra(X);

	for (int i = 1; i <= N; i++) {
		if (i == X)
			continue;
		dis_ans[i] += dis[i];
		ans = max(ans, dis_ans[i]);


	}

	/*for (int i = 1; i <= N; i++) {
		cout << dis_ans[i] << ' ';
	}*/

	cout << ans;

	return 0;


}