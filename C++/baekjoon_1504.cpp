#include <iostream>
#include <vector>
#include <queue>

#define INF 200001

vector<pair<int, int>> graph[800];
int d[800];

int d;

using namespace std;

int dijkstra(int s_node) {

	d[s_node] = 0;


	return 0;

}

int main(void) {

	int N, E;
	int v1, v2;

	cin >> N >> E;

	for (int i = 0; i < N; i++) {

		d[i] = INF;

	}

	for (int i = 0; i < E; i++) {
		int n1, n2, c;

		cin >> n1 >> n2 >> c;

		graph[n1 - 1].push_back(make_pair(n2 - 1, c));

	}

	cin >> v1 >> v2;

	//dijikst

	return 0;

}