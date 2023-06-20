#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool buttons[10] = { 0 };

bool check(int channel) {
	string ch = to_string(channel);

	for (auto it : ch) {
		if (buttons[it - '0']) {
			return false;
		}
	}
	return true;
}

int main(void) {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int buff;
		cin >> buff;
		buttons[buff] = true;
	}

	int ans = abs(N - 100);

	for (int i = 0; i < 1000000; i++) {
		if (check(i)) {
			int buff = abs(N - i) + to_string(i).size();
			ans = min(ans, buff);
		}
	}

	cout << ans;
	return 0;

}