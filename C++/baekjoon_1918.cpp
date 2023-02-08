#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {

	string infix;
	stack<char> s;
	cin >> infix;

	for (auto it : infix) {

		if (it == '+' || it == '-') {
			while (!s.empty() && s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.push(it);
			/*if (s.top() == '(')
				s.pop();*/
		}
		else if (it == '/' || it == '*') {
			while (!s.empty() && (s.top() == '/' || s.top() == '*')) {
				cout << s.top();
				s.pop();
			}
			s.push(it);
		}
		else if (it == '(') {
			s.push(it);
		}
		else if (it == ')') {
			while (s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
		else {
			cout << it;
		}
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}

	return 0;
}