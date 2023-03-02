#include <iostream>
#include <algorithm>

using namespace std;

int nodes[1000001];


int find_root(int node) {
	
	if (nodes[node] == node)
		return node;
	return nodes[node] = find_root(nodes[node]);
}

bool check_root(int node1, int node2) {

	int root1 = find_root(node1);
	int root2 = find_root(node2);

	return root1 == root2;
}

void merge_set(int node1, int node2) {
	int root1 = find_root(node1);
	int root2 = find_root(node2);

	if (root1 > root2)
		nodes[root1] = root2;
	else if(root2 > root1)
		nodes[root2] = root1;
}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, suffix, input1, input2;
	
	cin >> n >> m;
	
	for (int i = 0; i < n + 1; i++)
		nodes[i] = i;

	for (int i = 0; i < m; i++) {

		cin >> suffix >> input1 >> input2;

		if (suffix) {				//확인 연산
			if (check_root(input1, input2))
				cout << "yes" << '\n';
			else
				cout << "no" << '\n';
			
		}
		else {						//추가 연산
			merge_set(input1, input2);
		}

	}
	return 0;
}