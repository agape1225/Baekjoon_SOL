#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	int N, tmp;
	string perfix;
	float cache[26] = { 0 };
	//long double answer = 0.0;
	stack<long double> s;
	cout.precision(2);
	cin >> N >> perfix;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		cache[i] = tmp + 0.0;
	}


	for (int i = 0; i < perfix.size(); i++) {
		if (perfix[i] == '*') {
			long double num1 = s.top();
			s.pop();
			long double num2 = s.top();
			s.pop();
			s.push(num1 * num2);
		}
		else if (perfix[i] == '/') {
			long double num1 = s.top();
			s.pop();
			long double num2 = s.top();
			s.pop();
			s.push(num2 / num1);
		}
		else if (perfix[i] == '+') {
			long double num1 = s.top();
			s.pop();
			long double num2 = s.top();
			s.pop();
			s.push(num1 + num2);
		}
		else if (perfix[i] == '-') {
			long double num1 = s.top();
			s.pop();
			long double num2 = s.top();
			s.pop();
			s.push(num2 - num1);
		}
		else {
			s.push(cache[perfix[i] - 'A']);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << s.top();
	return 0;
}