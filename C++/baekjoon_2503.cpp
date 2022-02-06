#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check_string(string str) {

	if (str[0] == '0' || str[1] == '0' || str[2] == '0')
		return false;
	else {

		if (str[0] == str[1] || str[0] == str[2] || str[2] == str[1])
			return false;
		else
			return true;
	}
}



int main(void) {

	vector<string> arr;
	int ans[100][2];
	int size;
	string buff;
	int count = 0;

	cin >> size;

	for (int i = 0; i < size; i++) {

		cin >> buff >> ans[i][0] >> ans[i][1];
		arr.push_back(buff);

	}

	for (int num = 111; num < 1000; num++) {
		
		string tmp = to_string(num);		
		bool passed = true;

		if (check_string(tmp)) {

			for (int i = 0; i < size; i++) {		// arr은 던진 공, tmp는 비교할 공

				int strike = ans[i][0];
				int ball = ans[i][1] + strike;
				string throwed = arr[i];

				for (int j = 0; j < 3; j++) {		// strike 확인
					
					if (throwed[j] == tmp[j])
						strike--;
				}

				for (int j = 0; j < 3; j++) {
					
					if (throwed.find(tmp[j]) != string::npos)
						ball--;
				}

				if (!(strike == 0 && ball == 0))
					passed = false;
			}


			if (passed)
				count++;

		}

	}

	/*for (int i = 0; i < size; i++) {

		cout << arr[i] << ans[i][0] << ans[i][1] << endl;

	}*/

	cout << count;

	return 0;

}