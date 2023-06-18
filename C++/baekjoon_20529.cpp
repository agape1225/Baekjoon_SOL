#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_dis(string s1, string s2) {
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (s1[i] != s2[i])
			ans++;
	}

	return ans;
}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		vector<string> arr;
		string buff;
		int ans = 9876543210;
		
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> buff;
			arr.push_back(buff);
		}

		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				for (int k = j + 1; k < N; k++) {
					int buff = 0;

					buff += get_dis(arr[i], arr[j]);
					buff += get_dis(arr[j], arr[k]);
					buff += get_dis(arr[i], arr[k]);

					ans = min(ans, buff);
					if (ans == 0)
						break;
				}
				if (ans == 0)
					break;
			}
			if (ans == 0)
				break;
		}

		/*for (int i = 0; i < N - 2; i++) {

			int buff = 0;

			buff += get_dis(arr[i], arr[i + 1]);
			buff += get_dis(arr[i + 2], arr[i + 1]);
			buff += get_dis(arr[i], arr[i + 2]);

			ans = min(ans, buff);
		}*/
		cout << ans << '\n';
	}

	return 0;
}