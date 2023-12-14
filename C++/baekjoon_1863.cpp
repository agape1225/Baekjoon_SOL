#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	stack<pair<int, int>> s;
	int n;
	int count = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		if (i < n)
			cin >> x >> y;
		/*else
			y = 0;*/

		if (s.empty()) {
			s.push(make_pair(x, y));
		}
		else {

			if (s.top().second > y) {
				while (!s.empty() && s.top().second >= y) {
					count++;
					s.pop();
				}

				if (y != 0) {
					if (s.empty())
						s.push(make_pair(x, y));
					else if(s.top().second < y)
						s.push(make_pair(x, y));
				}
				//s.push(make_pair(x, y));
					
			}
			else
				s.push(make_pair(x, y));
		}
	}

	//cout << count;

	while (!s.empty()) {
		s.pop();
		count++;
	}

	cout << count;

	return 0;
}