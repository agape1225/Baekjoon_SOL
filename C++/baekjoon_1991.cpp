#include <iostream>
#include <cstdio>

using namespace std;

int graph[27][2];

/*전위순회(Preorder Traversal)
중위순회(Inorder Traversal)
후위순회(Postorder Traversal)*/

void preorderTraversal(int root) {

	int left = graph[root][0];
	int right = graph[root][1];

	//cout << root + 'A';
	printf("%c", root + 'A');

	if (left != -1) {
		preorderTraversal(left);
	}

	if (right != -1) {
		preorderTraversal(right);
	}
}

void inorderTraversal(int root) {
	int left = graph[root][0];
	int right = graph[root][1];

	if (left != -1) {
		inorderTraversal(left);
	}

	printf("%c", root + 'A');

	if (right != -1) {
		inorderTraversal(right);
	}
}

void postorderTraversal(int root) {

	int left = graph[root][0];
	int right = graph[root][1];

	if (left != -1) {
		postorderTraversal(left);
	}

	if (right != -1) {
		postorderTraversal(right);
	}

	printf("%c", root + 'A');

}

int main(void) {

	int N;
	char node, left, right;
	int node_num;
	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> node >> left >> right;
		
		node_num = node - 'A';

		if (left == '.') {
			graph[node_num][0] = -1;
		}
		else {
			graph[node_num][0] = left - 'A';
		}

		if (right == '.') {
			graph[node_num][1] = -1;
		}
		else {
			graph[node_num][1] = right - 'A';
		}

	}

	preorderTraversal(0);
	cout << endl;
	inorderTraversal(0);
	cout << endl;
	postorderTraversal(0);
}