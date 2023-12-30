#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main(void) {

	multiset<pair<int, int>> ms;
	map<int, int> m;
	int N, M, P, L, x;
	string cmd;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P >> L;
		ms.insert(make_pair(L, P));
		m.insert(make_pair(P, L));
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> cmd;

		if (cmd == "recommend") {
			cin >> x;
			if (x == -1) {
				cout << ms.begin()->second << '\n';
			}
			else {
				auto it = ms.end();
				cout << (--it)->second << '\n';
			}
		}
		else if (cmd == "add") {
			cin >> P >> L;
			ms.insert(make_pair(L, P));
			m.insert(make_pair(P, L));
		}
		else {
			cin >> P;
			ms.erase({ m[P], P });
		}
	}

	return 0;
}