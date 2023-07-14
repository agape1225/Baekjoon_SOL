#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int degree[1001] = { 0 };
		int construction_time[1001];
		int N, K;
		int X, Y, W;
		vector<int> graph[1001];
		int ans[1001];


		cin >> N >> K;

		for (int i = 0; i < N; i++) {
			cin >> construction_time[i + 1];
		}

		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			graph[X].push_back(Y);
			degree[Y]++;

		}

		queue<int> q;
		
		//차수가 0인녀석 찾기
		for (int i = 1; i <= N; i++) {
			if (degree[i] == 0) {
				q.push(i);
			}
			ans[i] = construction_time[i];
		}

		while (!q.empty()) {
			int top = q.front();
			q.pop();

			for (int i = 0; i < graph[top].size(); i++) {
				int next_node = graph[top][i];
				degree[next_node]--;

				ans[next_node] = max(ans[next_node], ans[top] + construction_time[next_node]);
				if (degree[next_node] == 0) {
					q.push(next_node);
				}
			}
		}

		cin >> W;
		cout << ans[W] << endl;
	}

	return 0;
}