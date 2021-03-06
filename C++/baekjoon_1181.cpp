#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define SIZE 20000

using namespace std;

bool comp(string s1, string s2) {
	return s1 < s2;
}

int main(void) {

	string voca[SIZE];
	int len[50] = { 0 };

	int size;

	cin >> size;

	for (int i = 0; i < size; i++) {
		cin >> voca[i];
		len[voca[i].size() - 1]++;
	}

	sort(voca, voca + size, comp);

	for (int i = 0; i < 50; i++) {
		if (len[i] == 1) {
			int buff = i + 1;
			for (int j = 0; j < size; j++) {
				if (voca[j].size() == buff)
					cout << voca[j] << endl;
			}
		}
		else if(len[i] > 1){
			vector<string> buff;

			for (int j = 0; j < size; j++) {
				if (voca[j].size() == i + 1)
					buff.push_back(voca[j]);
			}

			sort(buff.begin(), buff.end(), comp);

			for (int j = 0; j < len[i] - 1; j++) {
				if (buff[j] != buff[j + 1]) {
					cout << buff[j] << endl;
				}	
			}

			cout << buff[len[i] - 1] << endl;

		}
	}

	return 0;
}