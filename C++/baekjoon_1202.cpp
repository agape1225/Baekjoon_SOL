#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
int bag[300000];
pair<int, int> jew[300000];
priority_queue<int> q; //우선순위 큐 사용

int main(void) {
	//보석의 개수 N, 가방의 개수 K
	cin >> N >> K;
	//N개 만큼 보석의 정보 입력 받음
	for (int i = 0; i < N; i++)
		cin >> jew[i].first >> jew[i].second;
	//K개 만큼 가방의 최대 무게 입력 받음
	for (int i = 0; i < K; i++)
		cin >> bag[i];

	//무게를 기준으로 보석과 가방 오름차순 정렬
	sort(jew, jew + N);
	sort(bag, bag + K);

	long long result = 0;
	int idx = 0;
	//무게제한이 낮은 가방부터 최대한 비싼 보석을 넣는 방법
	for (int i = 0; i < K; i++)
	{
		//i번째 가방의 무게제한에 충족하는 보석 다 넣음
		while (idx < N && jew[idx].first <= bag[i])
			q.push(jew[idx++].second);
		//q 가장 처음에는 현재 기준 제일 비싼 보석이 들어있음
		if (!q.empty()) {
			result += q.top();
			q.pop();
		}
	}
	cout << result << "\n";
}