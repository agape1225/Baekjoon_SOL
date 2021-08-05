#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int size;
	vector<int> numbers_pos;
	vector<int> numbers_min;
	int count_one = 0;
	bool dir = false;
	int ans = 0;

	cin >> size;

	for (int i = 0; i < size; i++) {
		int buff;
		cin >> buff;
		
		if (buff > 0) {
			if (buff == 1)
				count_one++;
			else
				numbers_pos.push_back(buff);
		}
			
		else
			numbers_min.push_back(buff);

	}

	sort(numbers_pos.begin(), numbers_pos.end());
	sort(numbers_min.begin(), numbers_min.end());

	/*for (int i = 0; i < numbers_pos.size(); i++)
		cout << numbers_pos[i] << ' ';
	cout << endl;*/

	if (!numbers_pos.empty()) {
		for (int i = numbers_pos.size() - 1; i >= 1; i -= 2) {
			ans += numbers_pos[i] * numbers_pos[i - 1];

			if (i == 1)
				dir = true;
		}

		if (!dir && !numbers_pos.empty())
			ans += numbers_pos[0];
	}
		


	/*cout << ans << endl*/;

	dir = false;

	//cout << numbers_min.size();

	if (!numbers_min.empty()) {
		for (int i = 0; i < numbers_min.size() - 1; i += 2) {
			//cout << 1;
			ans += numbers_min[i] * numbers_min[i + 1];

			if (i == numbers_min.size() - 2)
				dir = true;
		}

		if (!dir && !numbers_min.empty())
			ans += numbers_min[numbers_min.size() - 1];
	}


	cout << ans + count_one;
	return 0;

}
