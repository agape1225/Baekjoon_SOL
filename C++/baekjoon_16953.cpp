#include <iostream>
#include <algorithm>
#define MAX 987654321

using namespace std;

int ans = MAX;
long long A, B;

void sol(int count, long long num) {
	if (num == B) {
		ans = min(ans, count);
	}
	else if (num < B) {
		sol(count + 1, num * 10 + 1);
		sol(count + 1, num * 2);
	}
}


int main(void) {

	

	cin >> A >> B;

	sol(0, A);


	if (ans == MAX)
		cout << -1;
	else
		cout << ans + 1;


	return 0;
}