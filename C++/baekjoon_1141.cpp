#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check_prefix(string s1, string s2) {

	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] != s2[i])
			return false;
	}
	return true;
}

int main(void) {

	vector<string> words;
	//vector<string> answer;
	int answer = 0;
	int size;


	cin >> size;

	for (int i = 0; i < size; i++) {
		string buff;
		cin >> buff;

		words.push_back(buff);
	}
	
	/*for (auto it = words.begin(); it != words.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;*/

	sort(words.begin(), words.end());

	/*for (auto it = words.begin(); it != words.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;*/

	//string standard = *words.begin();
	string past = *words.begin();
	int count = words.size();

	for (auto it = words.begin() + 1; it != words.end(); it++) {

		//past = *(it - 1);

		if (past.size() > (*it).size()) {
			past = *it;
			continue;
		}
		else {

			if (check_prefix(past, *it)) {

				count--;
			}
			else {
				
			}

			past = *it;

		}
	}
	
	/*if (count == 0)
		answer++;*/

	cout << count;

	return 0;
}