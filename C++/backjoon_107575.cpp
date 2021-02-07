#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {

	string x;
	string y;
	string z;

	char *cX;
	char *cY;

	cin >> x;
	cin >> y;

	cX = new char[x.size()];
	cY = new char[y.size()];

	int i, j;

	for (i = 0; i < x.size(); i++)
		cX[i] = x[i];

	cX[i] = NULL;

	
	for (j = 0; j < y.size(); j++)
		cY[j] = y[j];
	
	cY[j] = NULL;

	//cout << "1" << endl;

	//cout << cX << endl;
	//cout << cY << endl;

	int carry = 0;
	
	for (i = i - 1, j = j - 1; i > -1 && j > -1; i--, j--) {
		int buffX = cX[i] - '0';
		int buffY = cY[j] - '0';

		int buff = buffX + buffY;
		
		char buffC = ((buff + carry) % 10) + '0';

		z.push_back(buffC);

		if (buff + carry > 9)
			carry = 1;
		else
			carry = 0;
	}

	if (i > j) {
		for (; i > -1; i--) {
			int buff = cX[i] - '0';
			if (carry == 1) {
				buff++;
			}
			
			z.push_back((buff % 10) + '0');

			if (buff > 9)
				carry = 1;
			else
				carry = 0;

		}
	}
	else if (j > i) {
		for (; j > -1; j--) {
			int buff = cY[j] - '0';
			if (carry == 1) {
				buff++;
			}

			z.push_back((buff % 10) + '0');

			if (buff > 9)
				carry = 1;
			else
				carry = 0;

		}
	}

	if (carry == 1)
		z.push_back('1');

	char *ans = new char[z.size()];

	

	int k;

	for (k = 0; k < z.size(); k++) {
		ans[k] = z[z.size() - k - 1];
	}

	ans[k] = NULL;

	

	cout << ans;

	return 0;

}