#include <iostream>
#define SIZE 7

using namespace std;

void printArr(int* data, int* buff, int index, int N, int M) {
	if (index < M) {
		//cout << data[index] << " ";
		//buff[index] = 

		for (int i = 0; i < N; i++) {
			buff[index] = data[i];
			printArr(data, buff, index + 1, N, M);
		}

		//printArr(data, index + 1, M);

	}
	else {
		//buff[index]
		for (int i = 0; i < M; i++)
			cout << buff[i] << ' ';
		cout << '\n';
	}
}

int main(void) {
	int N, M;
	int data[SIZE];
	int buff[SIZE];

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		data[i] = i + 1;
	}

	printArr(data, buff, 0, N, M);

	//cout << N << M;

	return 0;
}