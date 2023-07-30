#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int cache[1005][1005] = { 0 };

int main(void) {
	
	string str1, str2;

	cin >> str1 >> str2;

	for (int i = 1; i <= str2.size(); i++) {
		for (int j = 1; j <= str1.size(); j++) {

			if (str2[i - 1] == str1[j - 1]) {
				cache[i][j] = cache[i - 1][j - 1] + 1;
			}
			else {
				cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
			}

		}
	}

	/*for (int i = 0; i <= str2.size(); i++) {
		for (int j = 0; j <= str1.size(); j++)
			cout << cache[i][j] << ' ';
		cout << endl;
	}*/

	int index_row, index_col;
	vector<char> ans;

	index_row = str2.size();
	index_col = str1.size();

	while (cache[index_row][index_col]) {

		if (cache[index_row][index_col] == cache[index_row - 1][index_col])
			index_row--;

		else if (cache[index_row][index_col] == cache[index_row][index_col - 1])
			index_col--;

		else {
			ans.push_back(str2[index_row - 1]);
			index_row--;
			index_col--;
		}
	}

	cout << cache[str2.size()][str1.size()] << endl;

	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i];
	}

	return 0;
}