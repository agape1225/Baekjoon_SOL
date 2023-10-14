#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> studys;

void get_nums(string str) {
	vector<string> ans;
	string tmp;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ')
			continue;
		if (str[i] == ',') {
			ans.push_back(tmp);
			tmp = "";
		}
		else
			tmp += str[i];
	}

	ans.push_back(tmp);
	studys = ans;
}



int main(void) {
	string input;
	string answer;
	vector<string> dic;
	getline(cin, input);

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '[') {
			
			answer += "[";
			i++;
			string tmp;
			while (input[i] != ']')
				tmp += input[i++];

			get_nums(tmp);

			vector<int> indexs;

			for (int j = 0; j < studys.size(); j++) {

				auto it = find(dic.begin(), dic.end(), studys[j]);

				if (it == dic.end()) {
					indexs.push_back(dic.size() + 1);
					dic.push_back(studys[j]);
				}
				else 
					indexs.push_back(it - dic.begin() + 1);
			}

			sort(indexs.begin(), indexs.end());

			for (int j = 0; j < indexs.size() - 1; j++)
				answer += " " + to_string(indexs[j]) + ",";
			
			answer += " " + to_string(indexs[indexs.size() - 1]);
			answer += " ]";
		}
		else {
			answer += input[i];
		}
	}

	cout << answer << endl;

	for (int i = 0; i < dic.size(); i++) {
		cout << '[' << i + 1 << ']' << ' ' << dic[i] << endl;
	}

	return 0;
}