#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;


int binary_search(int size, string ans, vector<pair<string, int>> pocket) {

	int mid;
	int begin = 0;
	int end = size - 1;
	string buff;


	while (begin <= end) {

		mid = (begin + end) / 2;
		buff = pocket[mid].first;

		if (ans == buff)
			return pocket[mid].second;
		else if (ans < buff) {
			end = mid - 1;
		}
		else {
			begin = mid + 1;
		}

	}

	return NULL;
}

int main(void) {


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	map<string, int> pocket;
	vector<string> num;

	string buff;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> buff;

		pocket[buff] = i + 1;
		num.push_back(buff);
	}

	for (int i = 0; i < M; i++) {

		int buffInt;
		stringstream ss;

		cin >> buff;

		ss.str(buff);
		ss >> buffInt;


		if (buffInt) {		//입력되는 값이 숫자일때
			cout << num[buffInt - 1] << '\n';
		}
		else {				//입력되는 값이 문자열일때

			
			cout << pocket[buff] << '\n';


		}
	}

	return 0;
}