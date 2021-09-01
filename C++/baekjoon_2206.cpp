#include <iostream>
#include <string>

#define SIZE 1000



using namespace std;

int map[SIZE][SIZE];

int main(void) {

	int N, M;
	
	string buff;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {

		cin >> buff;

		for (int j = 0; j < M; j++) {

			map[i][j] = buff[j] - '0';

		}

	}

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < M; j++) {

			cout << map[i][j] << ' ';

		}

		cout << endl;

	}

	return 0;

}