#include <iostream>

using namespace std;

long long cache[91] = { 0 };

int main(void) {
	int n;
	cin >> n;

	/*for (int i = 0; i < 91; i++)
		cache[i] = -1;*/

	cache[0] = 0;
	cache[1] = 1;

	for (int i = 2; i < 91; i++) {

		cache[i] = cache[i - 1] + cache[i - 2];

	}

	cout << cache[n];
	return 0;
}