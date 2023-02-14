#include <iostream>
#include <string>

using namespace std;

int main(void) {

	string input;
	int number_set[10] = { 0 };
	int count_set = 1;

	cin >> input;

	for (int i = 0; i < 10; i++) {
		number_set[i] = 1;
	}
	number_set[6]++;

	for (auto it : input) {
		int num = it - '0';
		
		if (num == 6 || num == 9) {
			if (number_set[6] == 0) {
				for (int i = 0; i < 10; i++) {
					number_set[i]++;
				}
				count_set++;
			}
			else {
				number_set[6]--;
			}
		}
		else {
			if (number_set[num] == 0) {
				for (int i = 0; i < 10; i++) {
					number_set[i]++;
				}
				number_set[6]++;
				number_set[num]--;
				count_set++;
			}
			else {
				number_set[num]--;
			}
		}
	}

	cout << count_set;

	return 0;

}