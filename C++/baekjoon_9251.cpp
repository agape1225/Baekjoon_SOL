#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int cache[1001][1001] = { 0 };

int main(void) {

	string s1, s2;

	cin >> s1 >> s2;

	int s1Size = s1.size();
	int s2Size = s2.size();

	for (int i = 1; i <= s2Size; i++) {

		char char2 = s2[i - 1];

		for (int j = 1; j <= s1Size; j++) {

			char char1 = s1[j - 1];

			if (char2 == char1) {

				cache[i][j] = cache[i - 1][j - 1] + 1;

			}
			else {

				cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);

			}

		}

	}

	cout << cache[s2Size][s1Size];

	return 0;

}