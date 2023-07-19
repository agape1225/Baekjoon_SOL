#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
int bag[300000];
pair<int, int> jew[300000];
priority_queue<int> q; //�켱���� ť ���

int main(void) {
	//������ ���� N, ������ ���� K
	cin >> N >> K;
	//N�� ��ŭ ������ ���� �Է� ����
	for (int i = 0; i < N; i++)
		cin >> jew[i].first >> jew[i].second;
	//K�� ��ŭ ������ �ִ� ���� �Է� ����
	for (int i = 0; i < K; i++)
		cin >> bag[i];

	//���Ը� �������� ������ ���� �������� ����
	sort(jew, jew + N);
	sort(bag, bag + K);

	long long result = 0;
	int idx = 0;
	//���������� ���� ������� �ִ��� ��� ������ �ִ� ���
	for (int i = 0; i < K; i++)
	{
		//i��° ������ �������ѿ� �����ϴ� ���� �� ����
		while (idx < N && jew[idx].first <= bag[i])
			q.push(jew[idx++].second);
		//q ���� ó������ ���� ���� ���� ��� ������ �������
		if (!q.empty()) {
			result += q.top();
			q.pop();
		}
	}
	cout << result << "\n";
}