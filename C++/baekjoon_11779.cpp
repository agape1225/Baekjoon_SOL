#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define INF 987654321

using namespace std;

vector<pair<int, int>> graph[1003];
int n, m;

//버스 요금
int fare[1003];
//경로 역추적
int visit[1003];
int start_node, end_node;

void print_node(int node, int count) {
	if (start_node == node) {
		cout << count << endl;
		//cout << visit[node] << ' ';
	}
	else {

		print_node(visit[node], count + 1);
		cout << visit[node] << ' ';
	}
}

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	visit[start] = start;
	fare[start] = 0;

	while (!pq.empty()) {
		int current_node = pq.top().second;
		int current_fare = -pq.top().first;
		pq.pop();

		if (fare[current_node] < current_fare) continue;

		for (int i = 0; i < graph[current_node].size(); i++) {
			int next_node = graph[current_node][i].first;
			int next_fare = graph[current_node][i].second + current_fare;

			

			if (fare[next_node] > next_fare) {
				fare[next_node] = next_fare;
				visit[next_node] = current_node;
				pq.push(make_pair(-next_fare, next_node));
			}
		}

	}
}

void init_fare() {
	for (int i = 1; i <= n; i++) {
		fare[i] = INF;
	}
}

int main(void) {

	int start, end, bus_fare;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> start >> end >> bus_fare;
		graph[start].push_back(make_pair(end, bus_fare));
	}

	cin >> start_node >> end_node;

	init_fare();
	dijkstra(start_node);
	

	cout << fare[end_node] << endl;
	print_node(end_node, 1);
	cout << end_node;

	return 0;

}