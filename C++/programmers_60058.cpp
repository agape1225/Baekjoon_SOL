#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<string> get_uv(string str) {
	int count_open = 0;
	int count_close = 0;
	int index = 1;

	if (str[0] == '(')
		count_open++;
	else
		count_close++;

	while (index < str.size() && count_open != count_close) {
		if (str[index] == '(')
			count_open++;
		else
			count_close++;
		index++;
	}

	string u = str.substr(0, index);
	string v = str.substr(index, str.size() - index);

	vector<string> ret;
	ret.push_back(u);
	ret.push_back(v);

	return ret;
}

bool is_balenced(string str) {
	stack<char> s;
	for (auto it : str) {
		if (it == '(')
			s.push(it);
		else {
			if (s.empty() || s.top() != '(') {
				return false;
			}

			else
				s.pop();
		}
	}
	return s.empty();
}

string bracket(string str) {
	if ((str == "") || is_balenced(str))
		return str;
	else {
		vector<string> uv = get_uv(str);
		string u = uv[0];
		string v = uv[1];

		if (is_balenced(u)) {
			return u + bracket(v);
		}
		else {
			string tmp = "(" + bracket(v) + ")";
			string new_u = u.substr(1, u.size() - 2);
			string final_u = "";

			for (auto it : new_u) {
				if (it == '(') {
					final_u += ")";
				}
				else {
					final_u += "(";
				}
			}
			return tmp + final_u;
		}
	}
}

string solution(string p) {
	string answer = "";
	answer = bracket(p);
	return answer;
}