#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;
int printArr[8];
int visited[8] = { 0 };
int N, M;

void sequence(int count) {

	if (count < M) {

		for (int i = 0; i < N; i++) {

			if (!visited[i]) {
				visited[i] = true;
				printArr[count] = arr[i];
				sequence(count + 1);
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
	int buff;

	for (int i = 0; i < N; i++) {
		cin >> buff;
		arr.push_back(buff);
	}

	sort(arr.begin(), arr.end());

	sequence(0);

	return 0;
}