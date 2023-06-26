#include <iostream>

using namespace std;

int tree[10000];

void postfix(int root, int size) {
	
	//함수의 끝
	if (root == -1)
		return;
	
	int node = tree[root];
	int left = -1;
	int right = -1;
	
	if (root + 1 < size) {
		if (tree[root + 1] < node) {
			left = root + 1;
			for (int i = left; i < size; i++) {
				if (node < tree[i]) {
					right = i;
					break;
				}
			}
		}
		else {
			right = root + 1;
		}
	}

	//cout << root << ' ' << left << ' ' << node << ' ' << right << ' ' << size << endl;

	if (left != -1 && right == -1)
		postfix(left, size);
	else
		postfix(left, right);
	postfix(right, size);
	cout << node << ' ';
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int input;
	int size = 0;

	while (cin >> input) {
		tree[size++] = input;
	}

	/*cin >> input;
	while (input) {
		tree[size++] = input;
		cin >> input;
	}
	for (int i = 0; i < size; i++) {
		cout << tree[i] << ' ';
	}
	cout << endl;*/
	postfix(0, size);

	return 0;

}