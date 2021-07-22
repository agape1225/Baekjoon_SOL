#include <iostream>
#include <string>

using namespace std;

bool is_palin(string s) {

	for (int i = 0; i < s.size(); i++) {

		if (s[i] != s[s.size() - (i + 1)])
			return false;

	}

	return true;

}

int main(void) {

	int T;

	cin >> T;

	for (int t = 0; t < T; t++) {

		string input;
		cin >> input;

		if (is_palin(input)) {

			cout << 0;

		}
		else {

			int index;

			for (int i = 0; i < input.size(); i++) {

				if (input[i] != input[input.size() - (i + 1)]) {

					index = i;
					break;
				}

			}

			string buff1 = input.substr(0, index) + input.substr(index + 1, input.size() - (index + 1));
			string buff2 = input.substr(0, input.size() - (index + 1)) + input.substr(input.size() - (index + 1) + 1, index);

			if (is_palin(buff1) || is_palin(buff2)) {
				cout << 1;
			}else{
				cout << 2;
			}

		}

		cout << endl;

	}

	return 0;
}