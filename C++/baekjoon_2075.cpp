#include <iostream>
#include <queue>

using namespace std;

vector<int> arr;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, tmp;
	
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> N;

	for (int i = 0; i < N * N; i++) {
		cin >> tmp;
		pq.push(tmp);

		if (pq.size() > N)
			pq.pop();
	}

	cout << pq.top() << endl;

	return 0;
}