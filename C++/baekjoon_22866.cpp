#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> building;
stack<int> s;
pair<int, int> cache[100000];

int main(void) {
	
	int N, tmp;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		building.push_back(tmp);
	}

	for (int i = 0; i < building.size(); i++) {
		int count = 0;
		int index = -1;

		while (!s.empty() && building[s.top()] <= building[i])
			s.pop();

		if(!s.empty())
			count = s.size();
		if(!s.empty())
			index = s.top();

		s.push(i);
		cache[i] = make_pair(count, index);
	}
	
	while (!s.empty())
		s.pop();
	
	for (int i = building.size() - 1; i >= 0; i--) {

		int count = cache[i].first;
		int index = cache[i].second;
		
		while (!s.empty() && building[s.top()] <= building[i])
			s.pop();
		
		if(!s.empty())
			count += s.size();
		if (!s.empty() && (index == -1 || abs(index - i) > (s.top() - i)))
			index = s.top();
		
		s.push(i);
		cache[i] = make_pair(count, index);
	}

	for (int i = 0; i < building.size(); i++) {
		int count = cache[i].first;
		if (count == 0)
			cout << 0 << '\n';
		else
			cout << count << ' ' << cache[i].second + 1 << '\n';
	}
	return 0;
}