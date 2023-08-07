#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> numbers;
int scores[1000006];
int cards[1000006];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// �÷��̾� �� �Է�
	int N;
	cin >> N;

	// �� �÷��̾��� ī�� �ѹ� �Է�
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		numbers.push_back(temp); // �� �÷��̾��� ī�� �ѹ� ����
		cards[temp] = 1; // Ư�� �÷��̾ �ش� ī�� �ѹ��� ������ �ִ��� üũ
	}

	// �����佺�׳׽��� ü ����
	// �� �÷��̾��� ī�� �ѹ��� ����� ���� üũ�ϸ鼭 �ش� ī�尡 �ִٸ�, ����
	for (int i = 0; i < N; i++)
	{
		// �ش� ī�� �ѹ��� ������� Ž��
		for (int j = numbers[i] * 2; j < 1000001; j += numbers[i])
		{
			// �ش� ī�� �ѹ��� ����� ī�尡 �����ϸ� ����
			if (cards[j] == 1)
			{
				scores[numbers[i]]++;
				scores[j]--;
			}
		}
	}

	// �� �÷��̾��� ���� ���
	for (int i = 0; i < N; i++)
		cout << scores[numbers[i]] << " ";

	return 0;
}