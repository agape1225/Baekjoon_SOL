#include <iostream>
#include <cmath>

using namespace std;

int solution(int r, int c, int ans_r, int ans_c, int n) {
	
	int half = n / 2;
	int loc;
	int buff_r, buff_c;
	int count = 0;

	if (ans_r < r + half) {

		if (ans_c < c + half) {
			loc = 1;
			buff_r = r;
			buff_c = c;
		}
		else {
			loc = 2;
			buff_r = r;
			buff_c = c + half;
		}

	}
	else {

		if (ans_c < c + half) {
			loc = 3;
			buff_r = r + half;
			buff_c = c;
		}
		else {
			loc = 4;
			buff_r = r + half;
			buff_c = c + half;
		}

	}
	if (half == 1) {
		return (pow(n, 2) / 4) * (loc - 1);
	}
	else {
		return (pow(n, 2) / 4) * (loc - 1) + solution(buff_r, buff_c, ans_r, ans_c, half);
	}

	

	//return 1;
}

int main(void) {
	int N, r, c;
	int ans;

	cin >> N >> r >> c;

	int dN = pow(2,N);

	ans = solution(0, 0, r, c, dN);

	cout << ans;

	return 0;
	
}