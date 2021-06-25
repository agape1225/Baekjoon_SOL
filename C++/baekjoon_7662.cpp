#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//priority_queue<int> pq;
	
	int T, k;

	cin >> T;

	for (int i = 0; i < T; i++) {

		multiset<int> s;
		cin >> k;
		char op;
		int n;

		for (int j = 0; j < k; j++) {

			cin >> op >> n;

			if (op == 'I') {
				//pq.push(n);
				s.insert(n);
			}
			else {
				if (!s.empty()) {
					if (n == 1) {
						s.erase(--s.end());
					}
					else {
						s.erase(s.begin());
					}
				}
					
			}

			/*cout << endl;

			for (auto it = s.begin(); it != s.end(); it++) {
				cout << *it << " ";
			}

			cout << endl << endl;*/

		}

		if (s.empty())
			cout << "EMPTY";
		else
			cout << *(--s.end())  << ' ' << *s.begin() << '\n';

	}

	return 0;
}