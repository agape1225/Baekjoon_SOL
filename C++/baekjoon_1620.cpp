#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>

using namespace std;

int binary_search(int begin, int end, int ans, vector<pair<string, int>> pocket) {

	int mid = (begin + end) / 2;

	return 0;
}

int main(void) {
	int N, M;
	//vector<string> pocket;
	vector<pair<string, int>> pocket;
	string buff;
	

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		//pair<string, int> v_buff;
		cin >> buff;
		
		pocket.push_back(make_pair(buff,i));
	}

	sort(pocket.begin(), pocket.end());

	for (int i = 0; i < M; i++) {

		int buffInt;
		stringstream ss;
		
		//cout << "----------------------------" << endl;

		cin >> buff;

		ss.str(buff);
		ss >> buffInt;

		//cout << buffInt << endl;

		if (buffInt) {		//입력되는 값이 숫자일때
			cout << pocket[buffInt - 1].first << '\n';
		}
		else {				//입력되는 값이 문자열일때

			//auto it = find(pocket.begin(), pocket.end(), buff);
			//auto it = lower_bound(pocket.begin(), pocket.end(), buff);
			//cout << *lower_bound(pocket.begin(), pocket.end(), buff) << '\n';


		}
	}

	return 0;
}