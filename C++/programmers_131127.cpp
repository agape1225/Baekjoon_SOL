#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
	int answer = 0;

	for (int i = 0; i < discount.size(); i++) {
		bool dir = true;
		for (int j = 0; j < want.size(); j++) {
			if (number[j] > count(
				discount.begin() + i,
				discount.begin() + i + 10,
				want[j])
				)
			{
				dir = false;
				break;
			}
		}
		if (dir)
			answer++;
	}

	return answer;
}