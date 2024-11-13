#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

bool buttons[10] = { 0 };

bool check_buttons(int channel) {

	string channel_str = to_string(channel);
	for (int i = 0; i < channel_str.size(); i++) {
		if (buttons[channel_str[i] - '0'])
			return false;
	}
	return true;
}

int main(void) {
	int N;
	
	int button_size;

	cin >> N >> button_size;

	for (int i = 0; i < button_size; i++) {
		int tmp;
		cin >> tmp;
		buttons[tmp] = true;
	}

	if (N == 100) {
		cout << 0;
		return 0;
	}

	int ans = abs(N - 100);

	for (int i = 0; i <= 1000000; i++) {

		if (check_buttons(i)) {
			int tmp = abs(N - i) + to_string(i).size();
			ans = min(ans, tmp);
		}
	}
	cout << ans;
	return 0;
}
