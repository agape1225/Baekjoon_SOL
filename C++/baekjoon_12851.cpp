#include <iostream>
#include <queue>

using namespace std;

bool visited[100001] = { 0 };

int main(void) {
	int N, K;
	queue<pair<int, int>> q;

	int		ans_count	= NULL;
	int		ans_case	= 0;
	bool	ans_dir		= false;

	cin >> N >> K;

	visited[N] = true;
	q.push(make_pair(0, N));

	while (!q.empty()) {

		int count = q.front().first;
		int current = q.front().second;
		q.pop();

		visited[current] = true;

		//cout << count << ' ' << current << endl;

		if (ans_dir && count > ans_count)
			continue;
		
		if (current == K && !ans_dir) {
			ans_dir = true;
			ans_case++;
			ans_count = count;
			continue;
		}

		if (ans_dir && current == K && ans_count == count) {
			ans_case++;
			continue;
		}

		if(current + 1 < 100001 && !visited[current + 1]){
			q.push(make_pair(count + 1, current + 1));
			//visited[current + 1] = true;
		}

		if (current - 1 >= 0 && !visited[current - 1]) {
			q.push(make_pair(count + 1, current - 1));
			//visited[current - 1] = true;
		}

		if (current * 2 < 100001 && !visited[current * 2]) {
			q.push(make_pair(count + 1, current * 2));
			//visited[current * 2] = true;
		}
	}

	cout << ans_count << endl << ans_case;

	return 0;

}