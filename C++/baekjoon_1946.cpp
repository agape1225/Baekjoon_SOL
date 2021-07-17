#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {

		int N;
		int buff1, buff2;
		int standard;
		vector<pair<int, int>> emp;
		int count = 1;
		cin >> N;

		for (int i = 0; i < N; i++) {

			cin >> buff1 >> buff2;
			emp.push_back(make_pair(buff1, buff2));

		}

		sort(emp.begin(), emp.end());

		standard = emp[0].second;

		for (int i = 1; i < N; i++) {

			if (standard > emp[i].second) {

				//cout << standard << " " << emp[i].second << endl;

				count++;
				standard = emp[i].second;
			}

		}

		cout << count << endl;

	}

	return 0;

}