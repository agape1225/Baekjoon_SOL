#include <iostream>

using namespace std;

int triangle[500][500] = {0};
int cache[500][500] = {0};


int main(void) {

	int n;
	int max = -1;
	int buff = NULL;


	cin >> n;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j <= i; j++) {
			/*cin >> buff;
			cout << buff << endl;;
			triangle[i][j] = buff;*/

			//cout << i << ' ' << j << endl;

			cin >> triangle[i][j];
		}
		
	}

	cache[0][0] = triangle[0][0];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {

			if (i == n - 1) {
				if (max < cache[i][j]) {
					max = cache[i][j];
				}
			}
			else {
				buff = cache[i][j] + triangle[i + 1][j];
				if (cache[i + 1][j] < buff)
					cache[i + 1][j] = buff;

				buff = cache[i][j] + triangle[i + 1][j + 1];
				if (cache[i + 1][j + 1] < buff)
					cache[i + 1][j + 1] = buff;
			}
		}
	}


	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {

			cout << cache[i][j] << ' ';
		}
		cout << endl;
	}*/

	cout << max;

	return 0;
}