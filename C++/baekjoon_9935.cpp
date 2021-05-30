#include <iostream>
#include <string>
#include <stack>

#define SIZE 1000002

using namespace std;

int main(void) {

	stack<char> s;
	stack<char> ans;
	char input[SIZE];
	char token[38];
	char compare[38];
	long long size = 0;

	cin >> input;
	cin >> token;

	for (int i = 0; token[i] != NULL; i++) {
		size++;
	}

	//cout << size;
	compare[size] = NULL;

	for (int i = 0; input[i] != NULL; i++) {
		//cout << input[i];
		if (input[i] == token[size - 1]) {

			bool dir = true;
			int is_empty = -1;
			int count = size - 1;
			compare[size - 1] = input[i];

			for (int j = size - 2; j > -1; j--) {
				
				if (!s.empty()) {
					compare[j] = s.top();
					s.pop();
				}
				else {
					is_empty = j;
					break;
				}
				
			}

			if (is_empty == -1) {
				for (int j = 0; j < size; j++) {
					if (compare[j] != token[j])
						dir = false;
				}
			}
			else {
				for (int j = is_empty + 1; j < size; j++) {
					s.push(compare[j]);
					continue;
				}
			}

			if (!dir) {
				for (int j = 0; j < size; j++) {
					s.push(compare[j]);
				}

			}

			

		}
		else {
			s.push(input[i]);
		}

	}

	if (s.empty()) {
		cout << "FRULA";
	}
	else {
		while (!s.empty()) {
			ans.push(s.top());
			s.pop();
		}

		while (!ans.empty()) {
			cout << ans.top();
			ans.pop();
		}
	}

	

	return 0;

}