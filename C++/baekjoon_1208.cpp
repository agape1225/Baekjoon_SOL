#include <iostream>

using namespace std;

int ans = 0;
int N, S;
int arr[40];
bool visited[40][40] = { 0 };

void get_ans(int left, int right, int sum) {
	
	if (left <= right) {
		cout << left << ' ' << right << ' ' << sum << endl;
		if (sum == S)
			ans++;
		else {
			if (!visited[left + 1][right]) {
				visited[left + 1][right] = true;
				get_ans(left + 1, right, sum - arr[left]);
			}
			
			if (!visited[left][right - 1]) {
				visited[left][right - 1] = true;
				get_ans(left, right - 1, sum - arr[right]);
			}	
		}
	}
}

int main(void) {
	
	cin >> N >> S;
	int tmp = 0;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		tmp += arr[i];
	}
	visited[0][N - 1] = true;
	get_ans(0, N - 1, tmp);

	cout << ans;

	return 0;
}