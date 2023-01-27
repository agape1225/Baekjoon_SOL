#include <iostream>

using namespace std;

int N, M;
int printArr[8];

void solution(int count, int start) {

	if (count < M) {

		for (int i = start; i <= N; i++) {
			printArr[count] = i;
			solution(count + 1, i);
		}

	}
	else {
		for (int i = 0; i < M; i++) {
			cout << printArr[i] << ' ';
		}
		cout << endl;
	}


}

int main(void) {

	cin >> N >> M;

	solution(0, 1);

	return 0;

}