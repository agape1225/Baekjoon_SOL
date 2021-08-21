#include <iostream>
#define SIZE 1001

using namespace std;

int tile[SIZE] = { 0 };

int main(void) {

	int n;
	tile[1] = 1;
	tile[2] = 2;

	cin >> n;

	for (int i = 3; i <= n; i++) {

		tile[i] = (tile[i - 1] + tile[i - 2]) % 10007;
	}
	
	/*for (int i = 0; i <= n; i++)
		cout << tile[i] << ' ';
	cout << endl;*/

	cout << tile[n] % 10007;
	


	return 0;

}