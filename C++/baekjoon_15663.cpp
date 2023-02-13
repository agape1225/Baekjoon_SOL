#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
bool visited[8] = { 0 };
//bool init_visited[9] = { 0 };
int arr_print[8] = { 0 };
vector<int> arr;

void print_arr(int count, int start) {

	if (count < M) {

		int last = -1;

		for (int i = 0; i < N; i++) {

			if (!visited[i] && arr[i] != last) {
				visited[i] = true;
				last = arr[i];
				arr_print[count] = arr[i];
				print_arr(count + 1, i + 1);
				visited[i] = false;
			}
		}
	}
	else {
		for (int i = 0; i < M; i++) {
			cout << arr_print[i] << ' ';
		}
		cout << endl;
	}

}

int main(void) {

	

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int buff;
		cin >> buff;
		arr.push_back(buff);
	}

	sort(arr.begin(), arr.end());

	print_arr(0, 0);

	return 0;

}