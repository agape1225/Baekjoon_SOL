#include <iostream>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main(void) {


	priority_queue<int, vector<int>, greater<int>> ms;
	int N, input;
	long long ans = 0;
	long long buff = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		ms.push(input);
	}

	if (N == 1) {
		cout << 0;
	}
	else {

		int num1;
		int num2;	
		while (ms.size() > 1) {
			num1 = ms.top();
			ms.pop();
			num2 = ms.top();
			ms.pop();

			ans += (num1 + num2);
			
			ms.push(num1 + num2);
			
		}
		cout << ans;

	}

	return 0;
}