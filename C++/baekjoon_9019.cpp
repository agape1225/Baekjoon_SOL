#include <iostream>
#include <queue>
#include <utility>
#include <string>

using namespace std;

int getNum(int num, string dir) {

	int ans = 0;

	if (dir == "D") {

		num = num * 2;
		if (num > 9999)
			num = num % 10000;
		ans = num;

	}
	if (dir == "S") {

		if (num == 0) {
			num = 9999;

		}else{
			num = num - 1;
		}
		ans = num;

	}
	if (dir == "L") {

		/*int buff[4] = { 0 };
		int buff_num = num;
		for (int i = 1000, j = 0; j < 4; i /= 10, j++) {
			buff[j] = buff_num / i;
			buff_num = buff_num % i;
		}

		ans += buff[1] * 1000;
		ans += buff[2] * 100;
		ans += buff[3] * 10;
		ans += buff[0] * 1;*/

		ans = (num % 1000) * 10 + (num / 1000);

	}
	if (dir == "R") {

		/*int buff[4] = { 0 };
		int buff_num = num;
		for (int i = 1000, j = 0; j < 4; i /= 10, j++) {
			buff[j] = buff_num / i;
			buff_num = buff_num % i;
		}

		ans += buff[3] * 1000;
		ans += buff[0] * 100;
		ans += buff[1] * 10;
		ans += buff[2] * 1;*/
		ans = (num % 10) * 1000 + (num / 10);

	}



	return ans;
}

int main(void) {

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {

		int A, B;
		string dir[4] = { "D", "S", "L", "R" };
		bool visited[10001] = { 0 };
		queue<pair<int, string>> q;

		cin >> A >> B;
		visited[A] = true;
		q.push(make_pair(A, ""));


		//Start BFS
		while (!q.empty()) {

			int num = q.front().first;
			string command = q.front().second;
			int ans = 0;
			q.pop();

			if (num == B) {
				cout << command << '\n';
				break;
			}

			/*for (auto it : dir) {

				int buff = getNum(num, it);
				if (!visited[buff]) {
					visited[buff] = true;
					q.push(make_pair(buff, command + it));
				}
			}*/

			ans = num * 2;
			if (ans > 9999)
				ans = ans % 10000;
			if (!visited[ans]) {
				visited[ans] = true;
				q.push(make_pair(ans, command + "D"));
			}

			if (num == 0)
				ans = 9999;
			else
				ans = num - 1;
			if (!visited[ans]) {
				visited[ans] = true;
				q.push(make_pair(ans, command + "S"));
			}

			//ans = (num % 1000) * 10 + (num / 1000);
			int buff[4] = { 0 };
			int buff_num = num;
			for (int i = 1000, j = 0; j < 4; i /= 10, j++) {
				buff[j] = buff_num / i;
				buff_num = buff_num % i;
			}

			ans = 0;
			ans += buff[1] * 1000;
			ans += buff[2] * 100;
			ans += buff[3] * 10;
			ans += buff[0] * 1;
			if (!visited[ans]) {
				visited[ans] = true;
				q.push(make_pair(ans, command + "L"));
			}

			ans = 0;
			ans += buff[3] * 1000;
			ans += buff[0] * 100;
			ans += buff[1] * 10;
			ans += buff[2] * 1;
			if (!visited[ans]) {
				visited[ans] = true;
				q.push(make_pair(ans, command + "R"));
			}

		}
	}

	return 0;
}