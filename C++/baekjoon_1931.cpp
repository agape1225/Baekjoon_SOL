#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>


using namespace std;

bool cmp(const pair<unsigned long, unsigned long> &a, 
		 const pair<unsigned long, unsigned long> &b) {

	if(a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main(void) {

	unsigned long num1;
	unsigned long num2;
	int size;

	vector<pair<unsigned long, unsigned long>> meeting;

	cin >> size;

	for (int i = 0; i < size; i++) {
		
		cin >> num1 >> num2;
		meeting.push_back(make_pair(num1, num2));
		
	}

	sort(meeting.begin(), meeting.end(), cmp);

	unsigned long first = meeting[0].first;
	unsigned long second = meeting[0].second;
	int ans = 1;


	for (int i = 1; i < size; i++) {

		if (second <= meeting[i].first) {
			ans++;
			first = meeting[i].first;
			second = meeting[i].second;
			
		}

		//cout << meeting[i].first << " " << meeting[i].second << '\n';

	}

	cout << ans;

	return 0;
}