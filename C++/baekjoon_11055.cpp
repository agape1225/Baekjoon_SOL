#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000];
int cache[1000] = { 0 };

int main(void) {
	
	int N;
	int ans = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		cache[i] = arr[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				cache[i] = max(cache[i], cache[j] + arr[i]);
			}
		}
		ans = max(ans, cache[i]);
	}

	cout << ans;
	
	return 0;

}