#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>


using namespace std;

int main(void) {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int M, tmp;
		vector<int> ans;
		priority_queue<int> max_queue;
		priority_queue<int, vector<int>, greater<int>> min_queue;

		cin >> M;
		
		int middle;
		cin >> middle;
		ans.push_back(middle);

		for (int i = 1; i < M; i++) {
			cin >> tmp;
			if (middle < tmp) {
				min_queue.push(tmp);
			}
			else {
				max_queue.push(tmp);
			}

			if ((i + 1) % 2 == 0)
				continue;
			if (min_queue.size() < max_queue.size()) {
				min_queue.push(middle);
				middle = max_queue.top();
				max_queue.pop();
				ans.push_back(middle);

			}
			else if (min_queue.size() > max_queue.size()) {
				max_queue.push(middle);
				middle = min_queue.top();
				min_queue.pop();
				ans.push_back(middle);
			}
			else
				ans.push_back(middle);
		}
		cout << (M + 1) / 2 << '\n';
		for (int i = 0; i < ans.size(); i++) {
			if ((i + 1) % 10 == 0)
				cout << ans[i] << '\n';
			else 
				cout << ans[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}