#include <iostream>

using namespace std;

int N, M;
int visited[9] = { 0 };
int printArr[9] = { 0 };

void combination(int count, int last) {

	if (count < M) {

		for (int i = 1; i <= N; i++) {
			if (!visited[i] && last < i) {
				
				visited[i] = true;
				printArr[count] = i;
				combination(count + 1, i);
				visited[i] = false;

			}
		}

	}
	else {
		for (int i = 0; i < M; i++) {
			cout << printArr[i] << ' ';
		}
		cout << '\n';
	}
}

int main(void) {
	
	cin >> N >> M;

	combination(0, 0);

}