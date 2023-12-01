#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
	vector<pair<pair<int, int>, bool>> coors;
	stack<int> s;
	bool dir = true;
	int N;
	int x, r;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x >> r;
		coors.push_back(make_pair(make_pair(x - r, i), false));
		coors.push_back(make_pair(make_pair(x + r, i), true));
	}

	sort(coors.begin(), coors.end());

	for (auto it : coors) {
		if (it.second) {
			if (s.top() == it.first.second)
				s.pop();
			else {
				dir = false;
				break;
			}
		}
		else
			s.push(it.first.second);
	}

	if (dir)
		cout << "YES";
	else
		cout << "NO";

	return 0;

}