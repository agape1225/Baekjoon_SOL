#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main(void) {

	int size;
	int buff1, buff2;
	int ans = 1;
	vector<pair<int, int>> nums;

	cin >> size;

	for (int i = 0; i < size; i++) {

		cin >> buff1 >> buff2;
		nums.push_back(make_pair(buff1, buff2));
	}

	sort(nums.begin(), nums.end(), compare);

	/*for (int i = 0; i < size; i++)
		cout << nums[i].first << ' ' << nums[i].second << endl;*/

	int start, end;
	start = nums[0].first;
	end = nums[0].second;

	for (int i = 1; i < size; i++) {

		if (nums[i].first >= end) {
			ans++;
			start = nums[i].first;
			end = nums[i].second;
		}

	}

	cout << ans;

	return 0;;

}