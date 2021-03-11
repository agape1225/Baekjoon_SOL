#include <iostream>
#include <algorithm>
#define SIZE 100000

using namespace std;

bool binarySearch(int arr[SIZE], int num, int size) {
	
	int start = 0;
	int end = size - 1;

	while (true) {

		int index = (start + end) / 2;


		if (arr[index] == num)
			return true;


		if (start == end)
			return false;

		


		if (arr[index] > num)
			end = index - 1;

		else
			start = index + 1;
	}
}

int main(void) {

	int arr[SIZE];
	int size;
	
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + size);

	/*for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	*/
	int loop;
	cin >> loop;

	for (int i = 0; i < loop; i++) {
		int buff;
		cin >> buff;

		if (binarySearch(arr, buff, size))
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}

	return 0;

}