#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main(void) {
	int N, M;
	vector<string> pocket;
	
	string buff;
	

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		
		cin >> buff;

		pocket.push_back(buff);
	}

	for (int i = 0; i < M; i++) {

		int buffInt;
		stringstream ss;
		
		//cout << "----------------------------" << endl;

		cin >> buff;

		ss.str(buff);
		ss >> buffInt;

		//cout << buffInt << endl;

		if (buffInt) {		//입력되는 값이 숫자일때
			cout << pocket[buffInt - 1] << '\n';
		}
		else {				//입력되는 값이 문자열일때

			auto it = find(pocket.begin(), pocket.end(), buff);
			cout << it - pocket.begin() + 1 << '\n';


		}
	}

	return 0;
}