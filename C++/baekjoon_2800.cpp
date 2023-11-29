#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[200] = { 0 };
bool index_visited[15] = { 0 };
string exp_input;
vector<string> exps;
vector<pair<int, int>> dic;

void print_exp(int index) {
	if (index == dic.size()) {
		
		string buff = "";
		for (int i = 0; i < exp_input.size(); i++) {
			if(!visited[i])
				buff.push_back(exp_input[i]);
		}
		//cout << "start: " << buff << endl;
		if(find(exps.begin(), exps.end(), buff) == exps.end())
			exps.push_back(buff);
	}
	else {
		int start_index = dic[index].first;
		int end_index = dic[index].second;
		
		visited[start_index] = visited[end_index] = true;
		print_exp(index + 1);
		visited[start_index] = visited[end_index] = false;
		print_exp(index + 1);
	}
}

int main(void) {
	
	stack<pair<int, int>> s;

	cin >> exp_input;
	
	for (int i = 0; i < exp_input.size(); i++) {
		if (exp_input[i] == '(') {
			s.push(make_pair(exp_input[i], i));
		}
		else if(exp_input[i] == ')') {
			dic.push_back(make_pair(s.top().second, i));
			s.pop();	
		}
	}

	//cout << dic.size();

	print_exp(0);

	sort(exps.begin(), exps.end());

	for (int i = 1; i < exps.size(); i++) {
		/*if (exps[i] == exp_input || answers.end() == find(answers.begin(), answers.end(), exps[i]))
			continue;*/
		cout << exps[i] << '\n';
		//answers.push_back(answers);
	}
	
	return 0;
	
}