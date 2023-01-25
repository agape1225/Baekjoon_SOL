#include <iostream>

using namespace std;

//dfs로 해보장

int visited[9] = { 0 };
int printArr[8] = { 0 };
int N, M;

void sequence(int count) {

	if (count < M) {

		for (int i = 1; i <= N; i++) {

			if (!visited[i]) {
				//cout << i << ' ';
				visited[i] = true;
				printArr[count] = i;
				sequence(count + 1);
				visited[i] = false;
			}

		}

	}
	if (count == M){
		for (int i = 0; i < M; i++) {
			cout << printArr[i] << ' ';
		}
		cout << endl;
		//return 0;
	}


}


int main(void) {

	cin >> N >> M;
	sequence(0);

	return 0;

}