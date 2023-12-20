#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		set<int> note1;
		vector<int> note2;

		int N, M, buff;
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> buff;
			note1.insert(buff);
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> buff;
			note2.push_back(buff);
		}

		//sort(note1.begin(), note1.end());

		for (auto it : note2) {
			if (note1.find(it) != note1.end()) {
				//cout << *note1.find(it) << endl;
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
	}

	return 0;
}