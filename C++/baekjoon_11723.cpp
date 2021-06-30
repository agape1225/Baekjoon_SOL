#include <iostream>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x = 1;

	for (int i = 0; i < 20; i++) {

		cout << i << ": ";
		x = x | (1 << i);

		cout << x << '\n';
	}

	return 0;

}