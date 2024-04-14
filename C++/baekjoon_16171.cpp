#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string S, K;
	string alpha_string;
	cin >> S >> K;

	for (auto it : S) {
		if (!('0' <= it && it <= '9')) {
			alpha_string.push_back(it);
		}
	}

	if (alpha_string.find(K) == string::npos) {
		cout << 0;
	}
	else
		cout << 1;

	return 0;
}