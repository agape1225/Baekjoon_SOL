#include <iostream>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

int ans[500001] = { 0 };

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<int> input;
	stack<pair<int, int>> s;
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int buff;
		cin >> buff;
		input.push_back(buff);
	}

	ans[0] = 0;
	s.push(make_pair(input[0], 1));

	for (int i = 1; i < N; i++) {

		int buff = (s.top()).first;

		if (buff < input[i]) {		//자신보다 큰 숫자를 만날때까지

			while (!s.empty() && (s.top()).first < input[i]) {
				s.pop();
			}
			
			if (s.empty()) {
				ans[i] = 0;
				
			}
			else {
				ans[i] = (s.top()).second;
			}
			s.push(make_pair(input[i], i + 1));

		}
		else {

			ans[i] = (s.top()).second;
			s.push(make_pair(input[i], i + 1));
		}

	}

	for (int i = 0; i < N; i++) {

		cout << ans[i] << ' ';
	}

	return 0;

}