#include <iostream>

using namespace std;

long pow(int x, int y, int z) {

	if (y == 0)
		return 1;

	long buff = pow(x, y / 2, z);

	if (y % 2)
		return (buff * buff) % z * x % z;
	else
		return (buff * buff) % z;
}

int main(void) {

	int a, b, c;
	cin >> a >> b >> c;

	cout << pow(a, b, c);

	return 0;
}