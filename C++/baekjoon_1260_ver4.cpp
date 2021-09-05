#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

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
		bool dir = false;


		if (!visited[buff]) {
			cout << buff << ' ';
			visited[buff] = true;
		}
			

		for (auto it = graph[buff].begin(); it != graph[buff].end(); it++) {

			if (!visited[*it]) {
				//visited[*it] = true;
				s.push(*it);
				dir = true;
				break;
			}
		}

		if(!dir)
			s.pop();

	}

}

void BFS(int start) {

	bool visited[SIZE] = { 0 };
	queue<int> q;

	q.push(start);
	visited[start] = true;
	
	while (!q.empty()) {

		int buff = q.front();
		q.pop();
		
		cout << buff << ' ';

		for (auto it = graph[buff].begin(); it != graph[buff].end(); it++) {

			if (!visited[*it]) {
				q.push(*it);
				visited[*it] = true;
			}

		}

	}

}

int main(void) {

	int buff1, buff2;

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {

		cin >> buff1 >> buff2;

		graph[buff1].push_back(buff2);
		graph[buff2].push_back(buff1);

	}

	for (int i = 1; i <= N; i++) {

		sort(graph[i].begin(), graph[i].end());

	}

	DFS(V);

	cout << endl;

	BFS(V);

	return 0;

}