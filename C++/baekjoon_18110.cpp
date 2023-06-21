#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<int> classes;

int main(void) {
	float n;
	int buff;

	cin >> n;

	if (n == 0) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		cin >> buff;
		classes.push_back(buff);
	}

	int standard = round(n * 0.15);
	int sum = 0;
	int ans;

	sort(classes.begin(), classes.end());

	for (int i = standard; i < n - standard; i++) {
		sum += classes[i];
	}

	ans = round(sum / (n - (standard * 2)));

	cout << ans;

	return 0;

}