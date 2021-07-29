#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <utility>

using namespace std;

vector<int> computer[10001];


int main(void) {
	
	int node, size;
	//set<pair<int, int>> ans;
	vector<int> ans;
	int max = -1;
	cin >> node >> size;

	for (int i = 0; i < size; i++) {
		int buff1, buff2;

		cin >> buff1 >> buff2;

		//computer[buff1].push_back(buff2);
		computer[buff2].push_back(buff1);
	}

	for (int i = 1; i <= node; i++) {

		queue<int> bfs_q;
		int count = -1;
		bool visited[10001] = { 0 };
		bfs_q.push(i);
		visited[i] = true;

		while (!bfs_q.empty()) {

			int buff = bfs_q.front();
			count++;
			bfs_q.pop();

			for (int j = 0; j < computer[buff].size(); j++) {
				if (!visited[computer[buff][j]]) {
					bfs_q.push(computer[buff][j]);
					visited[computer[buff][j]] = true;
				}
					
			}
			

		}

		//cout << count << endl;
		if (max < count) {
			ans.clear();
			ans.push_back(i);
			max = count;
			//ans.insert(make_pair(i, count));
		}
		else if (max == count) {
			ans.push_back(i);
		}
			//ans.insert(count);

	}

	for (auto i = ans.begin(); i != ans.end(); i++) {
		cout << (*i) << ' ';
	}
	
	return 0;

}