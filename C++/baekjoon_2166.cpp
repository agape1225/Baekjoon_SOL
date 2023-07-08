#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	vector<pair<double, double>> coordinate;
	int N;
	double sum = 0.0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		double buff1, buff2;
		cin >> buff1 >> buff2;
		coordinate.push_back(make_pair(buff1, buff2));
	}
	coordinate.push_back(*(coordinate.begin()));

	for (int i = 0; i < N; i++) {
		sum += coordinate[i].first * coordinate[i + 1].second;
		sum -= coordinate[i].second * coordinate[i + 1].first;
	}

	//sum /= 2;
	cout << fixed;
	cout.precision(1);
	cout << abs(sum / 2);

	return 0;


}