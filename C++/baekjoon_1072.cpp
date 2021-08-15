#include <iostream>

using namespace std;

int main(void) {

	long long X, Y;
	long long Z;
	long long ans = NULL;

	cin >> X >> Y;

	Z = 100 * Y / X;

	long long left = 1;
	long long right = X;
	long long mid = NULL;
	long long buff = NULL;

	while (left <= right) {
		
		mid = (left + right) / 2;
		
		buff = 100 * (Y + mid) / (X + mid);

		if (buff > Z) {
			
			//cout << buff << ' ' << Z << ' ' << mid << endl;
			
			right = mid - 1;
			ans = mid;


		}
		else {
			left = mid + 1;
		}

	}

	if (ans)
		cout << ans;
	else
		cout << -1;

	return 0;
}