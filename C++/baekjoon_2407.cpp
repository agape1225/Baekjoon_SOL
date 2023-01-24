#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string cache[101][101];

//0C0 = 1, 1C1 = 1, 1C0 = 1
//구글 없이 풀어보자! 화이또

string add(string num1, string num2) {
	string num = "";
	int sum = 0;
	int size = max(num1.size(), num2.size());

	for (int i = 0; i < size || sum; i++) {
		if (num1.size() > i) sum += num1[i] - '0';
		if (num2.size() > i) sum += num2[i] - '0';

		num += sum % 10 + '0';
		sum /= 10;
	}
	//reverse(num.begin(), num.end());
	return num;
}

/*string addNum(string s1, string s2) {

	int tmp = 0;

	string num1;
	string num2;
	string ans = "";

	if (s1.size() > s2.size()) {
		num1 = s1;
		num2 = s2;
	}
	else {
		num1 = s2;
		num2 = s1;
	}

	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	int num1Size = num1.size();
	int num2Size = num2.size();
	int i;

	for (i = 0; i < num2Size; i++) {
		int buff1 = num1[i] - '0';
		int buff2 = num2[i] - '0';

		ans += to_string(((buff1 + buff2 + tmp) % 10));
		//cout << i << " : " << ans << endl;

		tmp = (buff1 + buff2 + tmp) / 10;

	}

	if (num1Size == num2Size && tmp == 1) {
		ans += "1";

	}

	for (; i < num1Size; i++) {
		ans += to_string((tmp + (num1[i] - '0')) % 10);
		tmp = (tmp + (num1[i] - '0')) / 10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
*/
int main(void) {

	int n, m;
	cin >> n >> m;

	//r = n, c = m

	cache[0][0] = "1";
	cache[1][1] = cache[1][0] = "1";

	for (int i = 2; i < 101; i++) {

		for (int j = 0; j <= i; j++) {

			if (j == 0 || i == j) {
				cache[i][j] = "1";
			}
			else {
				cache[i][j] = add(cache[i - 1][j - 1], cache[i - 1][j]);
			}

			//cout << cache[i][j] << ' ';
		}
		//cout << endl;
	}

	reverse(cache[n][m].begin(), cache[n][m].end());
	cout << cache[n][m];


	return 0;

}