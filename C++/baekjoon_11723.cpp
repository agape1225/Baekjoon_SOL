#include <iostream>
#include <algorithm>
#define SIZE 3000000

using namespace std;

int set[SIZE];

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int index = 0;

	int size, buff;
	string input;

	cin >> size;

	for (int i = 0; i < size; i++) {

		//cout << i << endl;

		cin >> input;

		if (input == "add") {

			if (!binary_search(set, set + index, buff)){

				cin >> buff;
				set[index++] = buff;

				sort(set, set + index);

			}


		}
		else if (input == "remove") {

			cin >> buff;


		}
		else if (input == "check") {
			cin >> buff;



		}
		else if (input == "toggle") {
			cin >> buff;


		}
		else if (input == "all") {


			for (int j = 1; j < 21; j++) {


			}

		}
		else {				// empty



		}
	}

	return 0;

}