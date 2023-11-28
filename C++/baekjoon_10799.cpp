#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	stack<int> s;
	string input;
	int answer = 0;
	int count = 0;

	cin >> input;

	for (int i = 0; i < input.size(); i++) {

		if (s.size() == 0)
			count = 0;
		
		if (input[i] == '(') {
			if (input[i + 1] == '(') {
				count++;
				s.push('(');
			}
		}
		else {
			if (input[i - 1] == '(')
				answer += count;
			else {
				answer++;
				count--;
			}
				
		}
	}
	cout << answer;

	return 0;
}