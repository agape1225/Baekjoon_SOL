#include <iostream>
using namespace std;

long long n, b;
int arr[5][5];
int result[5][5];
int temp[5][5];

void solved(int v1[5][5], int v2[5][5]) {

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			temp[i][j] = 0;
			for (int k = 0; k < n; k++)
				temp[i][j] += (v1[i][k] * v2[k][j]);
			temp[i][j] %= 1000;
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			v1[i][j] = temp[i][j];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> b;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
		result[i][i] = 1;
	}
	while (b) {
		if (b % 2 == 1) {
			solved(result, arr);
		}
		solved(arr, arr);
		b /= 2;

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << result[i][j] << ' ';
		cout << endl;
	}

	return 0;
}