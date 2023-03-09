#include <iostream>
#include <algorithm>
#define MAX_NUM 987654321

using namespace std;

int cache[50001] = { 0 };

int main(void) {

	int n;
	cin >> n;

	/*for (int i = 1; i <= n; i++) {
		cache[i] = MAX_NUM;
	}*/

	//cache[0] = 0;
	cache[1] = 1;
	//cache[2] = 2;

	for (int i = 2; i <= n; i++) {
		
		int min_num = MAX_NUM;

		for (int j = 1; j * j <= i; j++) {
			int buff = i - j * j;
			min_num = min(min_num, cache[buff]);
		}
		cache[i] = min_num + 1;
	}

	cout << cache[n];

	return 0;

}