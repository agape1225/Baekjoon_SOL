#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	stack<pair<int, int>> s;
	int n;
	int count = 0;

	cin >> n;

	for (int i = 0; i <= n; i++) {
		int x, y;
		if (i < n)
			cin >> x >> y;
		else
			y = 0;
		while (!s.empty() && s.top().second >= y) {
			if(s.top().second > y)
				count++;
			s.pop();
		}
		s.push(make_pair(x, y));
	}
	cout << count;

	return 0;
}