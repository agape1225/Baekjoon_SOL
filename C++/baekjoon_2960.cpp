#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int n) {

	int count = 0;

	for (int i = 1; i <= n; i++) {

		if (n % i == 0)
			count++;

	}

	if (count == 2 && n != 1)
		return true;
	else
		return false;
}

int main(void) {

	int N, K;
	int count = 0;
	bool dir = false;
	int standard, mulCount;
	int ans = 0;
	vector<bool> num;

	

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		num.push_back(true);
	}

	while (count != K) {

		//cout << ans << endl;

		if (dir) {

			ans = standard * mulCount;
			if (ans > N) {

				dir = false;


			}
			else {

				if (num[ans - 1]) {
					num[ans - 1] = false;
					count++;
					
				}

				mulCount++;

			}

		}
		else {
			
			for (int i = 1; i < N; i++) {

				if (is_prime(i + 1) && num[i]) {
					ans = standard = i + 1;
					dir = true;
					num[i] = false;
					count++;
					mulCount = 2;
					break;
				}

			}
			

		}

		
			

	}

	cout << ans;

	return 0;
}