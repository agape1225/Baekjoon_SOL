#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

#define SIZE 1000000

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<int> coordinate;
	vector<int> coor;
	//set<int> coor;
	map<int, int> table;

	int buff;

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> buff;
		coordinate.push_back(buff);
		coor.push_back(buff);

	}

	sort(coor.begin(), coor.end());

	int count = -1;
	for (auto it = coor.begin(); it != coor.end(); it++) {

		if (table.find((*it)) != table.end())
			continue;
		
		count++;
		table.insert(make_pair((*it), count));

		
	}
	
	for (auto it = coordinate.begin(); it != coordinate.end(); it++) {

		cout << table[(*it)] << ' ';

	}

	return 0;

}