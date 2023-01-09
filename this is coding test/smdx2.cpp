#include <iostream>

using namespace std;

int main(int argc, char** argv) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		int x, y;
		int ans = 0;

		cin >> N >> x >> y;

		int digit = 1;
		while (digit < N) {
			digit *= 10;
		}

		if (digit != 1)
			digit = digit / 10;

		for (int i = digit; i > 0; i /= 10) {

			int buff = N / i;
			int num1 = ans * 10 + x;
			int num2 = ans * 10 + y;
			int num3 = ans;

			if (num1 > buff) {
				if (num2 > buff)
					ans = num3;
				else 
					ans = num2;
			}
			else {
				if (num2 > buff)
					ans = num1;
				else {
					if (num1 > num2)
						ans = num1;
					else
						ans = num2;
				}
			}
		}
		if(ans == 0)
			cout << '#' << t + 1 << ' ' << -1 << '\n';
		else
			cout << '#' << t + 1 << ' ' << ans << '\n';
	}

	return 0;
}