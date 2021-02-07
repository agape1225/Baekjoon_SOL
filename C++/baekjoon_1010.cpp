#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n, m;
		long long count = 0;

		cin >> n >> m;

		if (n == 1)
			count = m;
		else {
			for (int j = 0; j <= m - n; j++) {

				if (j == 0) 
					count++;
				else
					count += pow(n - 1,j) + 1;
			}
		}

		cout << count << endl;
	}

	return 0;
}