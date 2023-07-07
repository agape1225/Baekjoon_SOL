#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<long long, long long>> shapes;

int main(void) {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		double x, y;
		cin >> x >> y;
		shapes.push_back(make_pair(x, y));
	}

	shapes.push_back(*(shapes.begin()));

	double ans = 0.0;

	for (int i = 0; i < N; i++) {
		double num1 = shapes[i].first;
		double num2 = shapes[i + 1].second;
		ans += num1 * num2;
		
		num1 = shapes[i].second;
		num2 = shapes[i + 1].first;
		ans -= num1 * num2;
	}

	ans /= 2;
	cout << fixed;
	cout.precision(1);
	cout << abs(ans);

	return 0;

}