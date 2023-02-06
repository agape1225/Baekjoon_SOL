#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;
int printed[8];

void print_arr(int count, int started) {

	if (count < M) {
		for (int i = started; i < N; i++) {
			printed[count] = arr[i];
			print_arr(count + 1, i);
		}
	}
	else {
		for (int i = 0; i < count; i++) {
			cout << printed[i] << ' ';
		}
		cout << endl;
	}

}

int main(void) {

	cin >> N >> M;
	int buff;
	for (int i = 0; i < N; i++) {
		cin >> buff;
		arr.push_back(buff);
	}
	sort(arr.begin(), arr.end());
	print_arr(0, 0);


	return 0;
}