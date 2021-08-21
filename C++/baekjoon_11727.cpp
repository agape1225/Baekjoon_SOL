#include <iostream>
#define SIZE 1001

using namespace std;

int main(void) {
	
	int n;
	int tile[SIZE];

	tile[1] = 1;
	tile[2] = 3;

	cin >> n;

	for (int i = 3; i <= n; i++) {

		tile[i] = (tile[i - 1] + (tile[i - 2] * 2)) % 10007;

	}

	cout << tile[n] % 10007;

	return 0;

}