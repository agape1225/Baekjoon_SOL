#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

#define SIZE 1001

using namespace std;

int visited[SIZE] = { 0 };
int visited_bfs[SIZE] = { 0 };
vector<int> graph[SIZE];
stack<int> s;
queue<int> q;

int main(void) {

	int N, M, start_num;

	cin >> N >> M >> start_num;

	for (int i = 0; i < M; i++) {
		int buff1, buff2;
		cin >> buff1 >> buff2;

		graph[buff1].push_back(buff2);
		graph[buff2].push_back(buff1);
	}

	for (int i = 1; i <= N; i++) 
		sort(graph[i].begin(), graph[i].end());
	
	s.push(start_num);
	

	while (!s.empty()) {

		int buff = s.top();
		bool dir = false;

		if (!visited[buff]) {
			visited[buff] = true;
			cout << buff << ' ';
		}

		for (int i = 0; i < graph[buff].size(); i++) {

			if (!visited[graph[buff][i]]) {
				s.push(graph[buff][i]);
				dir = true;
				break;
			}

		}
			
		if (!dir)
			s.pop();

	}

	cout << endl;

	q.push(start_num);
	visited_bfs[start_num] = true;

	while (!q.empty()) {

		int buff = q.front();
		q.pop();
		cout << buff << ' ';

		for (int i = 0; i < graph[buff].size(); i++) {

			if (!visited_bfs[graph[buff][i]]) {
				visited_bfs[graph[buff][i]] = true;
				q.push(graph[buff][i]);
			}

		}

	}

	return 0;

}