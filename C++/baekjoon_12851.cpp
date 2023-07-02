#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, k;
int sec = 0;	//가장빠른시간을 저장할 변수
bool visited[100001];	//방문여부를 저장할 배열
int cnt = 0;	//빠른시간으로 동생을 찾는 방법의 개수

void bfs()
{
	queue<pair<int, int>>q;	//queue 선언 pair의 first는 현재위치, second는 이동에따른 시간을 저장
	q.push(make_pair(n, 0));	//시작위치와 0초를 push
	visited[n] = true;	//방문표시

	while (!q.empty())
	{
		int a = q.front().first;	//queue의 front값을 저장
		int b = q.front().second;

		q.pop();	//저장한 값을 queue에서 삭제
		visited[a] = true;	//방문표시

		if (sec == 0 && a == k)	//sec가 0이며, a == k인 경우는 처음으로 목적지에 도착한 경우
		{
			sec = b;	//걸린시간을 sec에 저장
			cnt++;	//방법개수 증가
		}
		else if (b == sec && a == k)	//목적지에 도착한 시간이 sec와 같으면서 목적지에 도착한 경우
		{
			cnt++;	//방법개수 증가
		}
		else if (sec != 0 && sec < b)	//sec가 저장되어있는데 sec보다 걸리시간이 더 큰 경우라면 continue
			continue;


		if (a + 1 <= 100001 && visited[a + 1] != true)	//a+1 이동한 경우
			q.push(make_pair(a + 1, b + 1));	//queue에 a+1과 b+1을 push, b는 시간
		if (a - 1 >= 0 && visited[a - 1] != true)	//a-1 이동한경우, 0일경우도 있기때문에 0까지 확인
			q.push(make_pair(a - 1, b + 1));
		if (a * 2 <= 100001 && visited[a * 2] != true)	//a*2 순간이동한경우
			q.push(make_pair(a * 2, b + 1));

	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;	//n과 k 입력

	bfs();	//bfs 탐색

	cout << sec << '\n';	//결과출력
	cout << cnt;

	return 0;
}