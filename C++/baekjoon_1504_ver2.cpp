#include <iostream>
#include <queue>
#include <utility>

#define MAX 800001

using namespace std;

vector<pair<int, int>> graph[801];

int N, E;
int buff1, buff2, buff3;
int num1, num2;

int Dijkstra(int start, int end) {

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	bool visited[801] = { 0 };
	int cost[801];

	for (int i = 1; i <= N; i++) {
		cost[i] = MAX;
	}

	pq.push(make_pair(0, start));
	cost[start] = 0;

	while (!pq.empty()) {

		pair<int, int> buff = pq.top();
		pq.pop();

		if (!visited[buff.second]) {

			visited[buff.second] = true;
			cost[buff.second] = buff.first;

			for (auto it = graph[buff.second].begin(); it != graph[buff.second].end(); it++) {

				int cost_buff = buff.first + (*it).second;

				if (cost[(*it).first] > cost_buff) {

					cost[(*it).first] = cost_buff;
					pq.push(make_pair(cost_buff, (*it).first));

				}

			}

		}

	}


	return cost[end];
}

int main(void) {

	cin >> N >> E;

	for (int i = 0; i < E; i++) {

		cin >> buff1 >> buff2 >> buff3;

		graph[buff1].push_back(make_pair(buff2, buff3));
		graph[buff2].push_back(make_pair(buff1, buff3));

	}

	cin >> num1 >> num2;

	int count1, count2, ans;

	count1 = Dijkstra(1, num1) + Dijkstra(num1, num2) + Dijkstra(num2, N);
	count2 = Dijkstra(1, num2) + Dijkstra(num2, num1) + Dijkstra(num1, N);

	//ans = count1 > count

	ans = count1 < count2 ? count1 : count2;

	if (ans > MAX)
		cout << -1;
	else
		cout << ans;

	//cout << count1 << ' ' << count2 << endl;

	return 0;

}