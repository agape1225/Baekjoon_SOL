#include <iostream>
#include <queue>
#include <utility>
#include <string>

using namespace std;

bool remote[10] = { 0 };
bool visited[500001] = { 0 };

int main(void) {

	int N, M, buff;
	int start_num = 100;
	queue<pair<int, int>> q;
	
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> buff;
		remote[buff] = true;
	}

	q.push(make_pair(100, 0));
	visited[100] = true;

	while (!q.empty()) {
		
		int channel = q.front().first;
		int count = q.front().second;
		q.pop();

		//cout << channel << endl;

		if (channel == N) {
			cout << count;
			return 0;
		}

		//번호 누르기
		for (int i = 0; i < 10; i++) {
			if (remote[i]){
				if (channel == 100) {
					q.push(make_pair(i, count + 1));
					visited[i] = true;

				}
				else if (!visited[channel * 10 + i]) {
					q.push(make_pair(channel * 10 + i, count + 1));
					visited[channel * 10 + i] = true;
				}
					
			}
		}

		if (channel - 1 >= 0) {
			if (!visited[channel - 1]) {
				q.push(make_pair(channel - 1, count + 1));
				visited[channel - 1] = true;
			}
		}
			
		if (!visited[channel + 1]) {
			q.push(make_pair(channel + 1, count + 1));
			visited[channel + 1] = true;
		}
	}

	return 0;
}