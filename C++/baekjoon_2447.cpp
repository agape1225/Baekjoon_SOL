#include <iostream>

using namespace std;

int main(void) {

	int input;

	cin >> input;

	for (int i = 0; i < input; i++) {
		for (int j = 0; j < input; j++) {

			if (input / 3 < i && i <= input / 3 * 2 && 
				input / 3 < j && j <= input / 3 * 2) {
				cout << ' ';
				continue;
			}
			if (((i / 3) * 3) < i && i < (((i / 3) + 1) * 3) - 1 &&
				((j / 3) * 3) < j && j < (((j / 3) + 1) * 3) - 1) {
				cout << ' ';
				continue;
			
			}
			cout << '*';
		}
		cout << endl;
	}
	return 0;
}