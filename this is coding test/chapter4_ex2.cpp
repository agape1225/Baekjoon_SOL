#include <iostream>

using namespace std;

bool check_three(int t, int m, int s) {

	if (t / 10 == 3 || t % 10 == 3)
		return true;
	else if (m / 10 == 3 || m % 10 == 3)
		return true;
	else if (s / 10 == 3 || s % 10 == 3)
		return true;
	else
		return false;

}

int main(void) {

	int N;
	int t, m, s;
	int count = 0;

	t = 0;
	m = 0;
	s = 0;

	cin >> N;

	while (!(t == N && m == 59 && s == 59)) {

		//cout << t << " " << m << " " << s << endl;

		if (check_three(t, m, s))
			count++;

		s++;

		if (s == 60) {
			s = 0;
			m++;
		}

		if (m == 60) {
			m = 0;
			t++;
		}

	}

	cout << count;


}