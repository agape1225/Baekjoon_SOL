#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	int N;
	int count = 0;

	cin >> N;

	for (int n = 0; n < N; n++) {
		string str;
		stack<char> s;

		cin >> str;

		for (auto it : str) {

			if (s.empty() || s.top() != it)
				s.push(it);
			else
				s.pop();
		}

		if (s.empty())
			count++;
	}

	cout << count;

	return 0;
}