#include <iostream>
#include <string>
#define SIZE 11

using namespace std;

int N, M;
int price[SIZE] = { 0 };

int main(void) {

	string ans;
	int min = 50;
	int min_num = NULL;
	bool is_zero = NULL;

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> price[i];

	}

	cin >> M;

	for (int i = 0; i < N; i++) {
		if (min > price[i]) {
			min = price[i];
			min_num = i;
		}
		else if (min == price[i]) {
			if (min_num < i)
				min_num = i;
		}
	}

	if (min_num == 0)
		is_zero = true;
	else
		is_zero = false;

	while (M >= min) {
		ans += to_string(min_num);
		M -= min;
	}
	int size = ans.size();
	string tmp;

	//cout << ans << endl;

	for (int i = 0; i < size; i++) {


		//cout << M << ' '  <<  tmp << endl;

		int tok = ans[i] - '0';
		bool dir = false;
		int buff = M + min;

		for (int j = N - 1; j > min_num; j--) {

			if (price[j] <= buff) {
				//ans[i] = (char)(j + 48);
				M = buff - price[j];
				is_zero = false;
				dir = true;
				tmp += (char)(j + 48);
				break;
			}

		}

		if (!dir) {

			if (i != size - 1) {

				if (tok == 0) {

					if (is_zero)

						M += min;
					else
						tmp += ans[i];
				}
				else {
					tmp += ans[i];
				}

			}
			else {
				tmp += ans[i];
			}

			
		}

		

	}

	cout << tmp;

	return 0;
}