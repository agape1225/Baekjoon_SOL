#include <iostream>
#include <vector>
#include <algorithm>

#define SIZE 9
#define GOAL 100

using namespace std;

vector<int> dwarf;
bool dir = false;


void set_combine(vector<int> buff, int index) {

	if (buff.size() == 7) {

		int sum = 0;
		for (int i : buff) {
			sum += i;
		}

		if (sum == GOAL && !dir) {
			sort(buff.begin(), buff.end());

			for (auto it = buff.begin(); it != buff.end(); it++) {
				cout << *it << endl;
			}

			dir = true;
		}

		
	}

	if (index == SIZE)
		return;

	set_combine(buff, index + 1);
	buff.push_back(dwarf[index]);
	set_combine(buff, index + 1);

}

int main(void) {

	
	vector<int> tmp;

	int buff;
	for (int i = 0; i < SIZE; i++) {
		cin >> buff;
		dwarf.push_back(buff);
	}

	set_combine(tmp, 0);

	//sort(dwarf.begin(), dwarf.end());

	/*for (int i = 0; i < 7; i++)
		cout << dwarf[i] << endl;;*/

	return 0;

}