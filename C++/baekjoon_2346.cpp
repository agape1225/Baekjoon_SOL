#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int N;
	int balloon[1000] = { 0 };
	bool visited[1000] = { 0 };
	int index = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> balloon[i];
	}

	for (int i = 0; i < N; i++) {

		int next = balloon[index];
		int count = abs(next);
		visited[index] = true;
		cout << index + 1 << ' ';

		if (i == N - 1)
			break;

		if (next > 0) {
			while (count > 0) {
				//cout << index << endl;
				index = (index + 1) % N;
				if (!visited[index])
					count--;

			}
		}
		else {
			while (count > 0) {
				index = index - 1;
				if (index < 0)
					index = N - 1;
				if (!visited[index])
					count--;
			}	
		}
	}

	return 0;
}