#include <iostream>
#include <cstdio>
#define SIZE 10

using namespace std;

int main(void) {
	int button[SIZE] = { 0,1,2,3,4,5,6,7,8,9 };
	int input, size;

	cin >> input;
	cin >> size;

	for (int i = 0; i < size; i++) {
		int buff;
		cin >> buff;
		button[buff] = -1;
	}

	if (97 < input && input < 104) {
		if (input >= 100)
			cout << input - 100;
		else
			cout << 100 - input;
	}
	else {
		int digitI = 0;
		int digit = 1;
		int dir = 1;
		while (true) {
			if (input / digit == 0)
				break;
			digit *= 10;
			digitI++;
		}
		digit /= 10;
		int buffDigit = digit;
		int indexP = input / digit;
		int indexM = input / digit;
		int num = 0;
		while (true) {

			//cout << "------------------------------" << endl << endl;
			//cout << indexP << endl << indexM << endl;
			if (!(-1 < indexM && indexP < 10)) {
				
				if (0 < indexM) {
					dir = 1;
				}
				else
					dir = -1;

				break;
			}
				
			if (button[indexP] != -1 || button[indexM] != -1) {

				if (button[indexP] != -1 && button[indexM] != -1) {
					if (buffDigit / 10 == 0)
						break;
					
					indexP = (input % buffDigit) / (buffDigit / 10);
					indexM = (input % buffDigit) / (buffDigit / 10);
					buffDigit = buffDigit / 10;
				}
				else {
					if (button[indexP] == -1) {
						dir = -1;
					}
					else {
						dir = 1;
					}
				}
			}
			else {
				indexP++;
				indexM--;
			}
			
			
		}

		//make num

		num = (input / (buffDigit * 10)) * (buffDigit * 10);
		int index = (input % (buffDigit * 10)) / buffDigit;

		while (true)
		{

			if (button[index] != -1) {
				num += index * buffDigit;
				buffDigit = buffDigit /= 10;

				if (!(buffDigit > 0))
					break;

				index = (input % buffDigit * 10) / buffDigit;

			}
			else {
				index += dir;
			}
		}


		if (dir > 0)
			cout << num - input + digitI;
		else
			cout << input - num + digitI;
	}
	return 0;
}