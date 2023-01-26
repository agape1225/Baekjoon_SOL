#include <iostream>

using namespace std;

int N, M;
int printArr[8] = { 0 };
int visited[9] = { 0 };

void combine(int start, int count) {

	if (count < M) {

		for (int i = start; i <= N; i++) {

			if (!visited[i]){

				visited[i] = true;
				printArr[count] = i;
				combine(i, count + 1);
				visited[i] = false;

			}


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
	combine(1, 0);

	return 0;
	

}