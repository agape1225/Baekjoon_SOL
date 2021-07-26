#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool check_range(int r, int c, int N) {

	if (r < 1 || c < 1)
		return false;
	else {

		if (r > N || c > N)
			return false;
		else
			return true;

	}

}

int main(void) {

	int N;
	cin >> N;

	cin.ignore();

	int r, c;
	r = 1;
	c = 1;

	string input;
	char buff_char;
	stringstream ss;

	//cout << 1;

	getline(cin, input);

	//cin >> input;
	input.erase(remove(input.begin(), input.end(), ' '), input.end());

	//cout << input;

	ss.str(input);

	while (ss >> buff_char) {

		//cout << buff_char << endl;

		if (buff_char == 'L') {

			if (check_range(r, c - 1, N)) {
				c--;
			}

		}
		else if (buff_char == 'R') {

			

			if (check_range(r, c + 1, N)) {

				//cout << 1 << endl;

				c++;
			}

		}
		else if (buff_char == 'U') {

			if (check_range(r - 1, c, N)) {

				cout << 1 << endl;

				r--;
			}

		}
		else {

			if (check_range(r + 1, c, N)) {
				r++;
			}

		}

	}

	cout << r << " " << c;

	return 0;


}