#include <iostream>
#include <vector>
#include <queue>

#define SIZE 100001

using namespace std;

vector<int> tree[SIZE];
int result[SIZE] = { 0 };
bool visited[SIZE] = { 0 };
queue<int> q;


void DFS() {

	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/

	q.push(1);
	visited[1] = true;

	while (!q.empty()) {

		int buff = q.front();
		q.pop();

		for (auto it = tree[buff].begin(); it != tree[buff].end(); it++) {

			if (!visited[*it]) {
				q.push(*it);
				result[*it] = buff;
				visited[*it] = true;
			}

		}

	}

}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	int buff1, buff2;

	for (int i = 0; i < N - 1; i++) {

		cin >> buff1 >> buff2;
		tree[buff1].push_back(buff2);
		tree[buff2].push_back(buff1);

	}

	DFS();

	for (int i = 2; i <= N; i++) {
		cout << result[i] << '\n';
	}

	return 0;

}