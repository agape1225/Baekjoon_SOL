#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int wine[10000];
	int cache[10000] = { 0 };

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> wine[i];
	}

	if (n == 1) {
		cout << wine[0];
		return 0;
	}

	if (n == 2) {
		cout << wine[0] + wine[1];
		return 0;
	}

	cache[0] = wine[0];
	cache[1] = wine[0] + wine[1];

	vector<int> buff = { wine[1], wine[2], wine[0] };
	sort(buff.begin(), buff.end());

	cache[2] = buff[1] + buff[2];

	/*for (auto it : buff) {
		cout << it << endl;
	}*/

	int buff1;
	int buff2;
	int buff3;

	for (int i = 3; i < n; i++) {

		/*if(cache[i -1] < cache[i - 2])
			buff1 =  cache[i - 2] + wine[i];
		else
			buff1 = cache[i - 3] + cache[i - 1] + wine[i];
		*/

		buff1 = max(cache[i - 3] + wine[i - 1] + wine[i], cache[i - 2] + wine[i]);
		buff2 = cache[i - 1];

		cache[i] = max(buff1, buff2);

	}

	cout << cache[n - 1];

	return 0;

}