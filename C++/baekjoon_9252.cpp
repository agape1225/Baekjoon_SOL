#include <iostream>
#include <string>
#include <utility>

using namespace std;

pair<int, string> cache[1001][1001];

int main(void) {
	string str1;
	string str2;
	/*int str1_size;
	int str2_size;*/

	cin >> str1 >> str2;
	
	cache[0][0] = make_pair(0, NULL);

	for (int i = 0; i < str1.size(); i++) {
		cache[0][i + 1] = make_pair(0, str1[i]);
	}

	for (int i = 0; i < str2.size(); i++) {
		cache[i + 1][0] = make_pair(0, str2[i]);
	}

	for (int i = 1; i <= str2.size(); i++) {
		for (int j = 1; j <= str1.size(); j++) {
			if (str2[i] == str1[j]) {
				
				int count = cache[i - 1][j - 1].first;
				string prev = cache[i - 1][j - 1].second;
				
				if (count == 0) {
					cache[i][j] = make_pair(count + 1, str2[i]);
				}
				else {

					cache[i][j] = make_pair(count + 1, prev + str2[i]);
				}
			}
			else {
				int count1 = cache[i - 1][j].first;
				string prev1 = cache[i - 1][j].second;
				int count2 = cache[i][j - 1].first;
				string prev2 = cache[i][j - 1].second;

				if (count1 < count2) {
					cache[i][j] = make_pair(count2, prev2);
				}
				else {
					cache[i][j] = make_pair(count1, prev1);
				}
			}
		}
	}

	for (int i = 0; i <= str2.size(); i++) {
		for (int j = 0; j <= str1.size(); j++) {
			cout << cache[i][j].first << ' ' << cache[i][j].second << '|';
		}
		cout << endl;
	}

	/*if(cache[str2.size()][str1.size()].first)
		cout << cache[str2.size()][str1.size()].second;*/

	return 0;

}