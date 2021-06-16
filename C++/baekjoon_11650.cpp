#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main(void) {

	vector<pair<int, int>> v;
	pair<int, int> p;
	pair<int, int> p_arr[100000];

	int input;
	int x, y;

	cin >> input;

	/*for (int i = 0; i < input; i++) {
		cin >> x;
		cin >> y;

		v.push_back(make_pair(x, y));
	}*/

	for (int i = 0; i < input; i++) {
		cin >> x;
		cin >> y;
		p_arr[i] = make_pair(x, y);
	}

	//sort(v.begin(), v.end());

	sort(p_arr, p_arr + input);

	for (int i = 0; i < input; i++) {

		cout << p_arr[i].first << " " << p_arr[i].second << "\n";

	}

	return 0;

}