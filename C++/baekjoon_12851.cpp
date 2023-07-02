#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, k;
int sec = 0;	//��������ð��� ������ ����
bool visited[100001];	//�湮���θ� ������ �迭
int cnt = 0;	//�����ð����� ������ ã�� ����� ����

void bfs()
{
	queue<pair<int, int>>q;	//queue ���� pair�� first�� ������ġ, second�� �̵������� �ð��� ����
	q.push(make_pair(n, 0));	//������ġ�� 0�ʸ� push
	visited[n] = true;	//�湮ǥ��

	while (!q.empty())
	{
		int a = q.front().first;	//queue�� front���� ����
		int b = q.front().second;

		q.pop();	//������ ���� queue���� ����
		visited[a] = true;	//�湮ǥ��

		if (sec == 0 && a == k)	//sec�� 0�̸�, a == k�� ���� ó������ �������� ������ ���
		{
			sec = b;	//�ɸ��ð��� sec�� ����
			cnt++;	//������� ����
		}
		else if (b == sec && a == k)	//�������� ������ �ð��� sec�� �����鼭 �������� ������ ���
		{
			cnt++;	//������� ����
		}
		else if (sec != 0 && sec < b)	//sec�� ����Ǿ��ִµ� sec���� �ɸ��ð��� �� ū ����� continue
			continue;


		if (a + 1 <= 100001 && visited[a + 1] != true)	//a+1 �̵��� ���
			q.push(make_pair(a + 1, b + 1));	//queue�� a+1�� b+1�� push, b�� �ð�
		if (a - 1 >= 0 && visited[a - 1] != true)	//a-1 �̵��Ѱ��, 0�ϰ�쵵 �ֱ⶧���� 0���� Ȯ��
			q.push(make_pair(a - 1, b + 1));
		if (a * 2 <= 100001 && visited[a * 2] != true)	//a*2 �����̵��Ѱ��
			q.push(make_pair(a * 2, b + 1));

	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;	//n�� k �Է�

	bfs();	//bfs Ž��

	cout << sec << '\n';	//������
	cout << cnt;

	return 0;
}