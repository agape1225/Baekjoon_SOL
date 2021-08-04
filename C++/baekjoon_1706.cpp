#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	
	int row, col;
	char puzzle[20][20];
	vector<string> list;

	cin >> row >> col;

	for (int i = 0; i < row; i++) {

		string input;
		cin >> input;

		for (int j = 0; j < col; j++) {
			puzzle[i][j] = input[j];
		}
	}

	/*for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << puzzle[i][j] << ' ';
		}
		cout << endl;
	}*/

	for (int i = 0; i < row; i++) {

		string buff;

		for (int j = 0; j < col; j++) {

			if (puzzle[i][j] == '#') {

				if (buff.size() > 1)
					list.push_back(buff);

				buff.clear();

			}
			else {
				buff += puzzle[i][j];
			}

		}

		if (buff.size() > 1)
			list.push_back(buff);
	}

	/*for (auto it = list.begin(); it != list.end(); it++)
		cout << *it << ' ';
	cout << endl;*/

	for (int i = 0; i < col; i++) {

		string buff;

		for (int j = 0; j < row; j++) {

			if (puzzle[j][i] == '#') {

				if (buff.size() > 1)
					list.push_back(buff);

				buff.clear();

			}
			else {
				buff += puzzle[j][i];
			}

		}

		if (buff.size() > 1)
			list.push_back(buff);
	}

	/*for (auto it = list.begin(); it != list.end(); it++)
		cout << *it << ' ';
	cout << endl;*/

	sort(list.begin(), list.end());

	if (list.size() > 0)
		cout << list[0];

	return 0;

}