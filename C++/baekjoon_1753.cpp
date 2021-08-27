#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <set>

#define SIZE 20001
#define MAX 999999999

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int V, E, start;
	vector < pair<int, int>> graph[SIZE];
	//multiset<pair<int, int>> pq;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	bool visited[SIZE] = { 0 };
	int cost[SIZE] = { 0 };

	int buff1, buff2, buff3;

	cin >> V >> E;
	cin >> start;

	for (int i = 0; i < E; i++) {
		
		cin >> buff1 >> buff2 >> buff3;
		graph[buff1].push_back(make_pair(buff3, buff2));

	}

	for (int i = 1; i <= V; i++) {
		cost[i] = MAX;
	}

	//pq.insert(make_pair(0,start));
	pq.push(make_pair(0, start));
	cost[start] = 0;

	while (!pq.empty()) {

		//pair<int, int> buff = (*pq.begin());
		pair<int, int> buff = pq.top();
		//pq.erase(pq.begin());
		pq.pop();

		if (!visited[buff.second]) {

			visited[buff.second] = true;
			cost[buff.second] = buff.first;

			for (auto it = graph[buff.second].begin(); it != graph[buff.second].end(); it++) {

				int cost_buff = buff.first + (*it).first;

				if (!visited[(*it).second] && cost[(*it).second] > cost_buff) {

					cost[(*it).second] = cost_buff;
					//pq.insert(make_pair(cost_buff, (*it).second));
					pq.push(make_pair(cost_buff, (*it).second));

				}

			}


		}

	}

	for (int i = 1; i <= V; i++) {

		if (cost[i] == MAX)
			cout << "INF";
		else
			cout << cost[i];
		cout <<  '\n';
	}

	return 0;

}