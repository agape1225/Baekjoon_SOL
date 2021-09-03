#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define SIZE 1001

using namespace std;

vector<int> graph[SIZE];
int N, M, V;

void DFS(int start) {

	bool visited[SIZE] = { 0 };
	stack<int> s;

	s.push(start);

	while (!s.empty()) {

		int buff = s.top();
		s.pop();

		if (!visited[buff])
			cout << buff << ' ';

		for (auto it = graph[buff].begin(); it != graph[buff].end(); it++) {

			if (!visited[*it]) {
				//visited[*it] = true;
				s.push(*it);
				break;
			}
		}

	}

}

void BFS(int start) {

	bool visited[SIZE] = { 0 };

}

int main(void) {

	int buff1, buff2;

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {

		cin >> buff1 >> buff2;

		graph[buff1].push_back(buff2);
		graph[buff2].push_back(buff1);

	}

	DFS(V);

	return 0;

}