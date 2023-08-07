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

	// 플레이어 수 입력
	int N;
	cin >> N;

	// 각 플레이어의 카드 넘버 입력
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		numbers.push_back(temp); // 각 플레이어의 카드 넘버 저장
		cards[temp] = 1; // 특정 플레이어가 해당 카드 넘버를 가지고 있는지 체크
	}

	// 에라토스테네스의 체 응용
	// 각 플레이어의 카드 넘버의 배수를 각각 체크하면서 해당 카드가 있다면, 결투
	for (int i = 0; i < N; i++)
	{
		// 해당 카드 넘버의 배수마다 탐색
		for (int j = numbers[i] * 2; j < 1000001; j += numbers[i])
		{
			// 해당 카드 넘버의 배수의 카드가 존재하면 결투
			if (cards[j] == 1)
			{
				scores[numbers[i]]++;
				scores[j]--;
			}
		}
	}

	// 각 플레이어의 점수 출력
	for (int i = 0; i < N; i++)
		cout << scores[numbers[i]] << " ";

	return 0;
}