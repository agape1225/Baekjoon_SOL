#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void) {
	int N;
	int max = 0;
	string title , ans;
	map<string, int> m;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> title;
		auto it = m.find(title);

		if (it == m.end()) {
			m.insert(make_pair(title, 1));
		}
		else {
			m[title]++;
		}
	}

	for (auto it : m) {
		if (max < it.second) {
			max = it.second;
			ans = it.first;
		}
	}

	cout << ans;
	
	return 0;
}