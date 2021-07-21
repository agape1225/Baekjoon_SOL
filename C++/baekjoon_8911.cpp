#include <iostream>
#include <sstream>
#include <utility>

using namespace std;

int main(void) {

	int T;

	cin >> T;

	for (int t = 0; t < T; t++) {

		string turtle;
		stringstream ss;
		pair<int, int> loc;
		char buff;
		int index = 0;
		int max[4] = { 0,0,0,0 };
		char dir[4] = {'N', 'E', 'S', 'W'};

		cin >> turtle;
		ss.str(turtle);

		loc.first = 0;
		loc.second = 0;

		while (ss >> buff) {

			if (buff == 'F') {

				if (dir[index] == 'N') {

					loc.second++;
					
					if (max[2] < loc.second) {
						max[2] = loc.second;
					}
					
				}
				else if (dir[index] == 'E') {
					
					loc.first++;

					if (max[0] < loc.first) {
						max[0] = loc.first;
					}
				}
				else if (dir[index] == 'S') {
					
					loc.second--;

					if (max[3] > loc.second) {
						max[3] = loc.second;
					}

				}
				else {
					
					loc.first--;

					if (max[1] > loc.first) {
						max[1] = loc.first;
					}

				}

			}
			else if (buff == 'B') {

				if (dir[index] == 'N') {

					loc.second--;

					if (max[3] > loc.second) {
						max[3] = loc.second;
					}

				}
				else if (dir[index] == 'E') {

					loc.first--;

					if (max[1] > loc.first) {
						max[1] = loc.first;
					}
				}
				else if (dir[index] == 'S') {

					loc.second++;

					if (max[2] < loc.second) {
						max[2] = loc.second;
					}

				}
				else {

					loc.first++;

					if (max[0] < loc.first) {
						max[0] = loc.first;
					}

				}

			}
			else if (buff == 'L') {
				if (index == 0)
					index = 3;
				else
					index--;
			}
			else {

				index = (index + 1) % 4;

			}

		}

		/*for (int j = 0; j < 4; j++) {

			cout << max[j] << endl;

		}*/

		//cout << loc.first << " " << loc.second << endl;

		int x = max[0] - max[1];
		int y = max[2] - max[3];

		cout << x * y << endl;

	}

	return 0;

}