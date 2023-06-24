/*
* 테스트 링크: https://www.acmicpc.net/problem/1753
* 왠만하면 우선순위 큐 사용
*/

#include <iostream>
#include <queue>

#define INF 987654321
#define MAX_NODE 20001

using namespace std;

vector<pair<int, int>> graph[MAX_NODE];
int ans[MAX_NODE];

int V, E;

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	ans[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();

		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i].first;
			int next_distance = graph[current][i].second + distance;
			if (ans[next] > next_distance) {
				ans[next] = next_distance;
				pq.push(make_pair(-next_distance, next));
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int start;

	cin >> V >> E >> start;

	int buff1, buff2, buff3;

	for (int i = 0; i < E; i++) {
		cin >> buff1 >> buff2 >> buff3;
		graph[buff1].push_back(make_pair(buff2, buff3));
	}



	for (int i = 1; i <= V; i++) {
		ans[i] = INF;
	}

	dijkstra(start);


	for (int i = 1; i <= V; i++) {
		if (ans[i] >= INF)
			cout << "INF" << '\n';
		else
			cout << ans[i] << '\n';
	}

	return 0;

}