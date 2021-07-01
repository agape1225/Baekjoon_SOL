#include <iostream>
#include <cmath>

using namespace std;

bool find(int bit, int num) {
	int tmpOr = bit | (1 << (num - 1));
	int tmpAnd = bit & tmpOr;

	//cout << tmpOr << " " << tmpAnd << " " << (int)pow(2, num) - 1  << endl;

	return tmpAnd == tmpOr;

}

int main(void) {

	//cout << (3 & 1) << endl;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num = 0;
	int size, buff;
	string input;

	cin >> size;

	for (int i = 0; i < size; i++) {

		//cout << i << endl;

		cin >> input;

		if (input == "add") {
			
			cin >> buff;
			num = num | (1 << (buff - 1));
			//cout << num << '\n';

		}
		else if (input == "remove") {

			cin >> buff;

			if (find(num, buff))
				num = num ^ (1 << (buff - 1));

		}
		else if (input == "check") {
			cin >> buff;

			if (find(num, buff))
				cout << 1 << '\n';
			else
				cout << 0 << '\n';

		}
		else if (input == "toggle") {
			cin >> buff;

			if (find(num, buff))
				num = num ^ (1 << (buff - 1));
			else
				num = num | (1 << (buff - 1));


		}
		else if (input == "all") {

			num = 1048575;

		}
		else {				// empty

			num = 0;

		}
	}

	return 0;

}