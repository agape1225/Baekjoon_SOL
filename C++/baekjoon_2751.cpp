#include <iostream>

using namespace std;

void mergeSort(int *arr, int size) {
	for (int i = 0; i < size - 1; i = i + 2) {
		if (arr[i] > arr[i + 1]) {
			int buff = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = buff;
		}
	}
	
}


int main(void) {
	int size;

	cin >> size;

	int *arr = new int[size];

	for (int i = 0; i < size; i++)
			cin >> arr[i];

	for (int i = 0; i < size; i++)
		cout << arr[i] << endl;

	return 0;
}