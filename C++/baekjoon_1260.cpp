#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

#define SIZE 1001



bool visited_dfs[SIZE] = { 0 };
bool visited_bfs[SIZE] = { 0 };

using namespace std;

int main(void){


	queue<int> q;
	stack<int> s;
	vector<int> graph[SIZE];

	int node, size, start;
	int buff1, buff2;

	cin >> node >> size >> start;

	for (int i = 0; i < size; i++) {

		cin >> buff1 >> buff2;
		graph[buff1].push_back(buff2);
		graph[buff2].push_back(buff1);

	}

	for (int i = 1; i <= node; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	for (int i = 1; i <= node; i++) {
		cout << i << " : ";
		for (int j = 0; j < graph[i].size(); j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}

	s.push(start);
	visited_dfs[start] = true;
	cout << start << ' ';

	while (!s.empty()) {

		bool dir = false;
		int buff = s.top();
		//s.pop();
		if (!visited_dfs[buff]) {
			visited_dfs[buff] = true;
			cout << buff << ' ';
		}
			

		for (int i = 0; i < graph[buff].size(); i++) {

			if (!visited_dfs[graph[buff][i]]) {
				s.push(graph[buff][i]);
				//visited_dfs[graph[buff][i]] = true;
				dir = true;
				break;
			}

		}

		if (!dir)
			s.pop();

	}

	cout << endl;

	q.push(start);
	visited_bfs[start] = true;

	while (!q.empty()) {

		int buff = q.front();
		q.pop();

		cout << buff << " ";

		for (int i = 0; i < graph[buff].size(); i++) {

			if (!visited_bfs[graph[buff][i]]) {
				visited_bfs[graph[buff][i]] = true;
				q.push(graph[buff][i]);
			}

		}

	}

	return 0;

}