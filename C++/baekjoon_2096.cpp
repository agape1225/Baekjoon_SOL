#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {

	int N;
	int col1, col2, col3;
	int max_buff1, max_buff2, max_buff3;
	int min_buff1, min_buff2, min_buff3;
	int buff1, buff2, buff3;
	int input1, input2, input3;

	cin >> N;

	cin >> input1 >> input2 >> input3;

	max_buff1 = min_buff1 = input1;
	max_buff2 = min_buff2 = input2;
	max_buff3 = min_buff3 = input3;

	for (int i = 1; i < N; i++) {

		cin >> col1 >> col2 >> col3;

		buff1 = col1 + max(max_buff1, max_buff2);
		buff2 = col2 + max(max(max_buff1, max_buff2), max_buff3);
		buff3 = col3 + max(max_buff3, max_buff2);

		max_buff1 = buff1;
		max_buff2 = buff2;
		max_buff3 = buff3;

		//cout << max_buff1 << ' ' <<  max_buff2 << ' ' <<  max_buff3 << endl;

		buff1 = col1 + min(min_buff1, min_buff2);
		buff2 = col2 + min(min(min_buff1, min_buff2), min_buff3);
		buff3 = col3 + min(min_buff3, min_buff2);

		min_buff1 = buff1;
		min_buff2 = buff2;
		min_buff3 = buff3;
	}

	cout << max(max_buff1, max(max_buff2, max_buff3)) << ' ' << min(min_buff1, min(min_buff2, min_buff3));

	return 0;

}