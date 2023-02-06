#include <iostream>
#include <stdlib.h>

using namespace std;

int visited[15];
int ans = 0;
int N;

bool check_queen(int count) {
	for (int i = 0; i < count; i++) {
		if (visited[i] == visited[count] ||  count - i == abs(visited[count] - visited[i]))
			return false;

	}
	return true;
}

void get_queen(int count) {
	if (count == N) {
		ans++;
	}
	else {
		for (int i = 0; i < N; i++) {
			//visited[count] = i;
			visited[count] = i;
			if (check_queen(count)) {
				get_queen(count + 1);
			}
		}
	}
}

int main(void) {

	cin >> N;
	get_queen(0);

	cout << ans;
	return 0;

}