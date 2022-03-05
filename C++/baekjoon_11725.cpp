#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[100001];
int ans[100001] = { 0 };

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = NULL;
	int root = 1;
	queue<int> q;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int buff1, buff2;

		cin >> buff1 >> buff2;

		graph[buff1].push_back(buff2);
		graph[buff2].push_back(buff1);
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	q.push(1);
	ans[1] = 1;

	while (!q.empty()) {

		int buff = q.front();
		q.pop();

		for (auto it = graph[buff].begin(); it != graph[buff].end(); it++) {

			if (ans[*it] == 0) {

				q.push(*it);
				ans[*it] = buff;

			}
		}
	}

	for (int i = 2; i <= N; i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}