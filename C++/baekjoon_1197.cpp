#include <iostream>
#include <vector>
#include <queue>

/*
* ���� ������
* �Է�
* ã��
* root Ȯ��
* �ƴϸ� ã��
*/

using namespace std;

priority_queue<pair<int, pair<int, int>>> edges;
int roots[10001];

int get_root(int node) {
	if (roots[node] == node) {
		return node;
	}
	else
		return roots[node] = get_root(roots[node]);
}

bool find(int node1, int node2) {

	int root1 = get_root(node1);
	int root2 = get_root(node2);

	if (root1 == root2)
		return true;
	else
		return false;
}

void union_node(int node1, int node2) {
	int root1 = get_root(node1);
	int root2 = get_root(node2);

	if (root1 > root2)
		roots[root1] = root2;
	else
		roots[root2] = root1;
}


int main(void) {
	int V, E;
	int count_node = 1;
	int ans = 0;

	cin >> V >> E;


	for (int i = 0; i <= V; i++) {
		roots[i] = i;
	}

	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;

		edges.push(make_pair(-C, make_pair(A, B)));
	}

	if (V == 1) {
		cout << 0;
		return 0;
	}
	
	while (count_node < V) {


		//cout << count_node << endl;

		int weight = -edges.top().first;
		int node1 = edges.top().second.first;
		int node2 = edges.top().second.second;


		edges.pop();

		//���� �� ��尡 ����Ǿ������� �׳� ����

		if (find(node1, node2)) {
			continue;
		}

		//�ƴϸ� ans�߰��ϰ� �� ����

		ans += weight;
		union_node(node1, node2);
		count_node++;
	}

	cout << ans;
	return 0;

}