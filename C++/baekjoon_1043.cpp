//�� �� �ִ�!
//person�迭�� ���δ� �־��
//true�� �ƴ� �׷�� false�� �ƴ� �������� ������
//true�� ���� ��Ƽ�� ���δ� true�� ���Ѵ�. �� ������ ���� Ǭ�� ����

#include <iostream>
#include <vector>

using namespace std;

int party_people[51];
vector<int> knows;
vector<int> party_set[51];

int find_root(int node) {
	if (party_people[node] == node)
		return node;
	return party_people[node] = find_root(party_people[node]);
}

int merge_node(int node1, int node2) {
	int root1 = find_root(node1);
	int root2 = find_root(node2);

	if (root1 > root2) {
		party_people[root1] = root2;
		return root2;
	}

	else if (root1 < root2) {
		party_people[root2] = root1;
		return root1;
	}
	else
		return root1;
		
}

int main(void) {

	
	int N, M;
	int T;
	int false_root = -1;

	cin >> N >> M >> T;

	for (int i = 1; i <= N; i++) {
		party_people[i] = i;
	}

	for (int i = 0; i < T; i++) {
		int buff;
		cin >> buff;
		knows.push_back(buff);
	}

	for (int i = 0; i < M; i++) {
		int persons, person;
		int prev = -1;
		cin >> persons;

		for (int j = 0; j < persons; j++) {
			cin >> person;
			party_set[i].push_back(person);
			if (prev == -1) {
				prev = person;
			}
			else {
				merge_node(prev, person);
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < M; i++) {
		int dir = true;
		for (auto person : party_set[i]) {
			for (auto known : knows) {
				if (find_root(person) == find_root(known)) {
					dir = false;
				}
			}
			if (!dir)
				break;
		}
		if (dir)
			ans++;
	}

	cout << ans;

	return 0;

}