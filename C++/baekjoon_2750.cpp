#include <iostream>
#define SIZE 1000

using namespace std;

int main(void) {

	int arr[SIZE];

	int size;

	cin >> size;

	for (int i = 0; i < size; i++)
		cin >> arr[i];
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int buff = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = buff;
			}
		}
	}

	for (int i = 0; i < size; i++)
		cout << arr[i] << endl;

	return 0;

}