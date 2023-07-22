#include <iostream>
#include <algorithm>
#include <vector>

#define SIZE 1000000

using namespace std;

int arr[SIZE];
vector<int> cache;

int main(void) {

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	cache.push_back(arr[0]);
	auto it = cache.begin();

	for (int i = 1; i < N; i++) {
		if (cache.back() < arr[i]) {
			cache.push_back(arr[i]);
		}
		else {
			it = lower_bound(cache.begin(), cache.end(), arr[i]);
			*it = arr[i];
		}
	}

	cout << cache.size();

	return 0;
}