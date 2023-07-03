#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 987654321

using namespace std;

vector<pair<int, int>> graph[101];
vector<int> items;
int cache[101];

int get_ans(int n, int m) {
	int count = 0;
	for (int i = 0; i < n; i++) {

		//cout << cache[i + 1] << ' ';

		if (cache[i + 1] <= m) {
			//cout << items[i] << ' ';
			count += items[i];
		}
	}
	//cout << endl;
	return count;
}

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;

	pq.push(make_pair(0, start));
	cache[start] = 0;

	while (!pq.empty()) {
		int node = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();

		for (int i = 0; i < graph[node].size(); i++) {
			int next_node = graph[node][i].first;
			int next_distance = distance + graph[node][i].second;

			if (next_distance < cache[next_node]) {
				cache[next_node] = next_distance;
				pq.push(make_pair(-next_distance, next_node));
			}
		}
	}
}

void init_cache(int n) {
	for (int i = 1; i <= n; i++) {
		cache[i] = INF;
	}
}

int main(void) {

	int n, m, r;
	int tmp;
	int start, end, weight;
	int ans = 0;

	cin >> n >> m >> r;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		items.push_back(tmp);
	}

	/*for (int i = 0; i < n; i++) {
		cout << items[i] << ' ';
	}
	cout << endl;*/

	for (int i = 0; i < r; i++) {
		cin >> start >> end >> weight;
		graph[start].push_back(make_pair(end, weight));
		graph[end].push_back(make_pair(start, weight));
	}

	for (int i = 1; i <= n; i++) {
		//ans_wight 초기화
		init_cache(n);

		//dijkstra 진행
		dijkstra(i);

		//최단거리의 범위 내에서 정담 count
		ans = max(ans, get_ans(n, m));
		//cout << ans << endl;

	}

	cout << ans;

	return 0;

}