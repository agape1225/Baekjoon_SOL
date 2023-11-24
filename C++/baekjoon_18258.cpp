#include <iostream>

using namespace std;

class queue {
private:
	int _front;
	int _end;
	int cache[2000000];

public:
	queue() {
		_front = 0;
		_end = 0;
	}
	bool empty() {
		return _front == _end;
	}
	void push(int num) {
		cache[_end++] = num;
		//cout << _end << ' ' << cache[_end - 1] << endl;
	}
	int pop() {
		if (empty())
			return -1;
		return cache[_front++];
	}
	int size() {
		return _end - _front;
	}
	int front() {
		if (empty())
			return -1;
		return cache[_front];
	}
	int back() {
		if (empty())
			return -1;
		return cache[_end - 1];
	}
};
queue a;
int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;

	for (int n = 0; n < N; n++) {
		string cmd;
		int tmp;
		cin >> cmd;

		if (cmd == "push") {
			cin >> tmp;
			a.push(tmp);
		}
		if (cmd == "pop") {
			cout << a.pop() << '\n';
		}
		if (cmd == "size") {
			cout << a.size() << '\n';
		}
		if (cmd == "empty") {
			cout << a.empty() << '\n';
		}
		if (cmd == "front") {
			cout << a.front() << '\n';
		}
		if (cmd == "back") {
			cout << a.back() << '\n';
		}
	}
	return 0;

}