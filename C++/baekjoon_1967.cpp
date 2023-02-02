#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> graph[10001];
int visited[10001] = { 0 };
int n;
int ansWeight = -1;
int ansNode = -1;


void dfs(int root, int weight) {

	int max = -1;

	if (ansWeight < weight) {
		ansWeight = weight;
		ansNode = root;
	}

	for (auto it : graph[root]) {
		if (!visited[it.first]) {
			visited[it.first] = true;
			dfs(it.first, it.second + weight);
		}
	}

	/*for (int i = 1; i <= n; i++) {
		if (!visited[i] && graph[root][i] > 0) {
			
			visited[i] = true;
			dfs(i, graph[root][i] + weight);

		}
	}*/

}

int main(void) {

	cin >> n;
	int node1, node2, weight;

	for (int i = 0; i < n - 1; i++) {
		cin >> node1 >> node2 >> weight;
		graph[node1].push_back(make_pair(node2, weight));
		graph[node2].push_back(make_pair(node1, weight));
		
		/*graph[node1][node2] = weight;
		graph[node2][node1] = weight;*/
	}

	visited[1] = true;
	dfs(1, 0);

	//cout << buff.first << ' ' << buff.second << endl;
	
	for (int i = 0; i < 10001; i++)
		visited[i] = false;

	visited[ansNode] = true;
	dfs(ansNode, 0);

	cout << ansWeight;

	return 0;

}