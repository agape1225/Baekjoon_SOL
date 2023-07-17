//위상 정렬이네
//같은 vector 사용: 연습한번 더 한다고 생각하면 될듯

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, assistant;
vector<int> graph[1001];
vector<int> ans;
int degree[1001] = { 0 };
queue<int> q;

bool check_arr() {
	
	for (int i = 1; i <= N; i++) {
		if (degree[i] > 0)
			return false;
		
	}
	return true;
}

int main(void) {

	

	cin >> N >> M;

	//입력 받기
	for (int i = 0; i < M; i++) {
		cin >> assistant;
		int parent = NULL;
		int	child = NULL;
		int temp;
		for (int j = 0; j < assistant; j++) {
			cin >> temp;
			if (parent == NULL) {
				parent = temp;
			}
			else {
				child = temp;
				graph[parent].push_back(child);
				degree[child]++;
				parent = child;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		//cout << node << ' ';
		ans.push_back(node);

		for (int i = 0; i < graph[node].size(); i++) {
			int next_node = graph[node][i];
			degree[next_node]--;

			if (degree[next_node] == 0) {
				q.push(next_node);
			}
		}
	}

	if (check_arr()) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << ' ';
		}
	}
	else
		cout << 0;

	return 0;

}