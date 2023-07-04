#include <iostream>
#define MOD 1000000007

using namespace std;

long long power(long long s, long long mod) {

	long long ans = 1;
	while (mod) {
		if (mod % 2)
			ans = ans * s % MOD;
		mod = mod /  2;
		s = s * s % MOD;
	}

	return ans;
}

//long long power(long long s, long long mod) {
//
//	if (mod == 1)
//		return s;
//	long long ans = 1;
//	long long tmp = power(s, mod / 2);
//	ans = tmp * tmp;
//	if (mod % 2)
//		ans = ans * s;
//	
//	return ans % MOD;
//}


int main(void) {

	int M;
	long long N, S;
	long long ans = 0;

	cin >> M;

	for (int i = 0; i < M; i++) {
		
		cin >> S >> N;

		ans += (N * (power(S, MOD - 2))) % MOD;
	}

	cout << ans % MOD;

	return 0;
}