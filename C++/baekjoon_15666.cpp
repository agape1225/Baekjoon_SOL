#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;
int N, M, buff;
int print_arr[8];

void comb(int count, int start) {
	if (count == M) {
		for (int i = 0; i < count; i++) {
			cout << print_arr[i] << ' ';
		}
		cout << '\n';
	}
	else {
		for (int i = start; i < N; i++) {
			
			if (
				i == 0 
				|| 
				(i > 0 && arr[i] != arr[i - 1])) {
				print_arr[count] = arr[i];
				comb(count + 1, i);
			}
		}
	}
}

int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> buff;
		arr.push_back(buff);
	}

	sort(arr.begin(), arr.end());

	comb(0, 0);

	return 0;
}