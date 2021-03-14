#include <iostream>

using namespace std;

/*int GCD(int x, int y) {

	if (x % y == 0)
		return y;
	else
		GCD(y, x % y);
}*/

int main(void) {

	int x, y;

	cin >> x >> y;

	if (x < y) {
		int buff = x;
		x = y;
		y = buff;
	}

	int orginX = x;
	int orginY = y;

	//int gcd = GCD(x, y);
	
	while (x % y != 0) {
		int buff1 = y;
		int buff2 = x % y;
		x = buff1;
		y = buff2;
	}

	cout << y << endl;
	cout << orginX * orginY / y;

	return 0;
}