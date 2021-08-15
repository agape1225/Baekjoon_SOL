#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

bool check_range(int r, int c) {

	if (!(0 < r && r < 9))
		return false;
	else {

		if (!(0 < c && c < 9))
			return false;

	}

	return true;

}

int main(void) {

	string input;
	stringstream ss;
	int count = 0;

	vector<vector<int>> dir = { {2,1}, {2,-1}, {-2,1}, {-2,1} };

	cin >> input;

	ss.str(input);

	char c_buff;
	int r;
	int c;

	ss >> c_buff;
	ss >> r;

	c = c_buff - 96;
	
	for (int i = 0; i < 4; i++) {

		if (check_range(r + dir[i][0], c + dir[i][1]))
			count++;
		

	}
	
	for (int i = 0; i < 4; i++) {

		if (check_range(r + dir[i][1], c + dir[i][0]))
			count++;


	}

	cout << count;

	return 0;

}