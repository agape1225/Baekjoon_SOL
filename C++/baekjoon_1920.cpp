#include <iostream>
#include <algorithm>
#include <cstdio>
//#define SIZE 100001

using namespace std;

int arr[100001];

bool binarySearch(int num, int size) {
	
	int start = 0;
	int end = size - 1;
	int index;

	while (end - start >= 0) {

		index = (start + end) / 2;

		//if (0 > index || index >= size)
		//	return false;

		if (arr[index] == num)
			return true;

		if (arr[index] > num)
			end = index - 1;

		else
			start = index + 1;
	}
	
	return false;
}

/*void Solution(int n, int key) {

	int start = 0;
	int end = n - 1;
	int mid;

	while (end - start >= 0) {
		mid = (start + end) / 2;

		if (arr[mid] == key) {   //key 값이 배열의 중앙 값과 같을때
			printf("1\n");
			return;

		}
		else if (arr[mid] > key) { //key 값이 배열의 중앙 값보다 작을때 (왼쪽으로)
			end = mid - 1;

		}
		else {  //key 값이 배열의 중앙 값보다 클때 (오른쪽으로)
			start = mid + 1;
		}
	}

	printf("0\n");
	return;
}*/


int main(void) {

	int size;
	
	scanf("%d", &size);
	//cin >> size;
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + size);

	int loop;
	int buff;
	scanf("%d", &loop);

	for (int i = 0; i < loop; i++) {
		scanf("%d", &buff);
		//cin >> buff;
		//binarySearch(buff, size);

		if (binarySearch(buff, size))
			printf("1\n");
		else
			printf("0\n");
	}

	return 0;

}