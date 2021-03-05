#include <iostream>
#define SIZE  1000000

using namespace std;

int arr[SIZE];

int main(void) {

	int x;
	cin >> x;

	arr[0] = 0;

	for (int i = 1; i < SIZE; i++) {

		int num1 = 1000, num2 = 1000, num3 = 1000;
		int count = 0;

		if (i < 3)
			arr[i] = 1;
		else {

			if ((i + 1) % 3 == 0) {
				num1 = arr[(i + 1) / 3 - 1] + 1;
			}
			if ((i + 1) % 2 == 0) {
				num2 = arr[(i + 1) / 2 - 1] + 1;
			}

			num3 = arr[i - 1] + 1;

			num1 = num1 > num2 ? num2 : num1;
			num3 = num1 > num3 ? num3 : num1;

			arr[i] = num3;


			/*if (i + 1 % 6 == 0) {
				int buff1, buff2;

				buff1 = arr[(i + 1) / 3 - 1] + 1;
				buff2 = arr[(i + 1) / 2 - 1] + 1;

				num1 = buff1 > buff2 ? buff2 : buff1;


			}
			else {

				if ((i + 1) % 3 == 0) {
					num1 = arr[(i + 1) / 3 - 1] + 1;
				}
				else if ((i + 1) % 2 == 0) {
					num1 = arr[(i + 1) / 2 - 1] + 1;
				}
				else {
					num1 = arr[i - 1] + 1;
				}

			}

			num2 = arr[i - 1] + 1;

			arr[i] = num1 > num2 ? num2 : num1;*/

		}
	}

	cout << arr[x - 1] << endl;
	

	return 0;
}