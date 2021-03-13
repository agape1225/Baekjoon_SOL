#include <cstdio>
#include <queue>

using namespace  std;

int main(void) {
	queue<int> q;

	int N;
	scanf_s("%d", &N);

	for (int i = 0; i < N; i++) {
		q.push(i + 1);
	}

	bool dir = true;
	while (q.size() > 1) {
		//printf("%d", q.size());

		if (dir) {
			q.pop();
			dir = false;
		}
		else {
			int buff;
			buff = q.front();
			q.pop();
			q.push(buff);
			dir = true;
		}
	}

	printf("%d", q.front());

	return 0;
}