#include <iostream>

using namespace std;

int N;
long long B;

int matrix[5][5];
int result[5][5];

void cal_matrix(int matrix1[5][5], int matrix2[5][5]) {
	
	int tmp[5][5] = { 0 };
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int ans = 0;
			for (int k = 0; k < N; k++) {
				ans += matrix1[i][k] * matrix2[k][j];
			}
			tmp[i][j] = ans % 1000;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			matrix1[i][j] = tmp[i][j];
		}
	}
	
}

int main(void) {
	cin >> N >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrix[i][j];	
		}
		result[i][i] = 1;
	}

	while (B) {
		if (B % 2) {
			cal_matrix(result, matrix);
		}
		cal_matrix(matrix, matrix);
		B = B / 2;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}