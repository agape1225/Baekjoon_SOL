#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	
	int N, M, buff;
	vector<int> target;
	deque<int> dq;
	int count = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		dq.push_back(i + 1);
	}
	
	for (int i = 0; i < M; i++) {
		cin >> buff;
		target.push_back(dq[buff - 1]);
	}

	for (int i = 0; i < M; i++) {
		int target_num = target[i];

		//왼쪽인지 오른쪽인지 최솟값 구하기
		int right_count = 0;
		int left_count = 0;
		int right_index = 0;
		int left_index = 0;

		while (dq[right_index] != target_num) {
			right_index = (right_index + 1) % dq.size();
			right_count++;
		}

		while (dq[left_index] != target_num) {
			if (left_index - 1 == -1)
				left_index = dq.size() - 1;
			else
				left_index--;
			left_count++;
		}

		//그대로 답 구하기
		if (right_count <= left_count) {
			while (dq.front() != target_num) {
				int tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);
				count++;
			}
			dq.pop_front();
		}
		else {
			while (dq.front() != target_num) {
				int tmp = dq.back();
				dq.pop_back();
				dq.push_front(tmp);
				count++;
			}
			dq.pop_front();
		}
	}
	cout << count;

	return 0;

}