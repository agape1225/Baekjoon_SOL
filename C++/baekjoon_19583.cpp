#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(void) {
	int count = 0;
	map<string, string> m;
	set<string> s;
	string S, E, Q;
	string start_time, name;

	cin >> S >> E >> Q;

	while (cin >> start_time >> name) {
		if (start_time <= S) {
			auto it = m.find(name);
			if (it == m.end()) {
				m.insert(start_time, name);
			}
		}
		if (E <= start_time && start_time <= Q) {
			if (s.find(name) != s.end()) {
				auto it = m.find(name);

				if (it != m.end()) {
					count = count + 1;
					s.insert(name);
				}
			}
		}
	}
	cout << count;

	return 0;
}