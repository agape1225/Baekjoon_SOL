#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int cache[1001][1001] = { 0 };

int main(void) {

	string s1;
	string s2;
	
	cin >> s1 >> s2;

	int s1Size = s1.size();
	int s2Size = s2.size();

	/*for (int i = 0; i <= s1Size; i++)
		cache[0][i] = 0;

	for (int i = 0; i <= s2Size; i++)
		cache[i][0] = 0;*/

	for (int i = 1; i <= s2Size; i++) {
	
		char standard = s2[i - 1];
		
		for (int j = 1; j <= s1Size; j++) {

			if (standard == s1[j - 1]) {

				cache[i][j] = cache[i - 1][j - 1] + 1;

			}
			else {
				cache[i][j] = max(cache[i][j - 1], cache[i - 1][j]);
			}

		}
	}

	cout << cache[s2Size][s1Size];

	return 0;

}