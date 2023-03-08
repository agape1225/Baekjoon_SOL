#include <iostream>
#include <algorithm>
#define MAX 987654321

using namespace std;

int cache[500001] = { 0 };

int main(void) {

	int n;
	cin >> n;

	cache[1] = 1;

	for (int i = 2; i <= n; i++) {

		int min_num = MAX;

		for (int j = 1; j * j <= i; j++) {
			int tmp = i - j * j;
			min_num = min(min_num, cache[tmp]);
		}
		cache[i] = min_num + 1;
	}

	cout << cache[n];
	return 0;

}