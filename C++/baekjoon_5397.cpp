#include <iostream>
#include <list>

using namespace std;

int main(void) {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string L;
		list<char> l;

		cin >> L;

		auto ptr = l.begin();

		for (auto it : L) {
			if (it == '<') {
				if (ptr != l.begin())
					ptr--;
			}
			else if (it == '>') {
				if (ptr != l.end())
					ptr++;
			}
			else if (it == '-') {
				if (ptr != l.begin())
					ptr = l.erase(--ptr);
			}
			else {
				ptr = l.insert(ptr, it);
				ptr++;
			}
		}
		for (auto it : l)
			cout << it;

		cout << endl;
	}
	return 0;
}