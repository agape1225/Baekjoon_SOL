#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
	int N, command;
	deque<int> dq;
	vector<int> commands;

	cin >> N;

	for (int n = 0; n < N; n++) {
		cin >> command;
		commands.push_back(command);
	}

	for (int i = N - 1; i >= 0; i--) {

		command = commands[i];
		int target = N - i;

		if (command == 1)
			dq.push_front(target);

		else if (command == 2) {
			int tmp = dq.front();
			dq.pop_front();
			dq.push_front(target);
			dq.push_front(tmp);
		}
		else
			dq.push_back(target);
	}
	
	for (auto it : dq)
		cout << it << ' ';

	return 0;
}