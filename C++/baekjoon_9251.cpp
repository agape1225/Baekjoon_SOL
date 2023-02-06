#include <iostream>
#include <string>

using namespace std;

int cache[10001][1001] = { 0 };

int main(void) {

	string s1, s2;
	int size1, size2;
	
	cin >> s1 >> s2;

	size1 = s1.size();
	size2 = s2.size();

	for (int i = 1; i <= size1; i++) {
		for (int j = 1; j <= size2; j++) {
			char standard = s1[i - 1];
			if (s2[j - 1] == standard) {
				cache[i][j] = max(cache[i - 1][j - 1] + 1, cache[i - 1][j]);
			}
			else {
				cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
			}
		}
	}

	cout << cache[size1][size2];

	return 0;

}