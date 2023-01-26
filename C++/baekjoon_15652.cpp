#include <iostream>

using namespace std;

int printArr[8];
int visited[9] = { 0 };
int N, M;

void inDesc(int count, int start) {

	if (count < M) {


		for (int i = start; i <= N; i++) {
			printArr[count] = i;
			inDesc(count + 1, i);
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
	inDesc(0, 1);

}