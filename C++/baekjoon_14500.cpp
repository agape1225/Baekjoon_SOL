#include <iostream>

using namespace std;

int paper[500][500];

//data
int polymino[19][2][4]{
	{
		{0,0,1,1},
		{0,1,0,1}
	},
	{
		{0,0,0,0},
		{0,1,2,3}
	},
	{
		{0,1,2,3},
		{0,0,0,0}
	},
	{
		{0,1,1,1},
		{2,0,1,2}
	},
	{
		{0,1,2,2},
		{0,0,0,1}
	},
	{
		{0,1,0,0},
		{0,0,1,2}
	},
	{
		{0,0,1,2},
		{0,1,1,1}
	},
	{
		{0,1,1,1},
		{0,0,1,2}
	},
	{
		{0,1,2,2},
		{1,1,0,1}
	},
	{
		{0,0,0,1},
		{0,1,2,2}
	},
	{
		{0,0,1,2},
		{0,1,0,0}
	},
	{
		{0,1,1,2},
		{0,0,1,1}
	},
	{
		{0,0,1,1},
		{1,2,0,1}
	},
	{
		{0,1,1,2},
		{1,0,1,0}
	},
	{
		{0,0,1,1},
		{0,1,1,2}
	},
	{
		{0,0,0,1},
		{0,1,2,1}

	},
	{
		{0,1,1,2},
		{1,0,1,1}

	},
	{
		{0,1,1,1},
		{1,0,1,2}

	},
	{
		{0,1,1,2},
		{0,0,1,0}

	}
};
int N, M;

bool checkRange(int x, int y) {

	if (x < 0 || x >= N)
		return false;
	if (y < 0 || y >= M)
		return false;
	return true;
}

int main(void) {

	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> paper[i][j];
		}
	}

	int max = -1;
	int buff = NULL;
	bool isPassed = NULL;

	//ㅈㄴ 구현 문제인듯
	//O(N*M) -> 20 * 500 * 500 = 5000000 2초안에 충분히 가능함 -> Brute force

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			for (int i = 0; i < 19; i++) {
				
				buff = 0;
				isPassed = true;
				
				for (int j = 0; j < 4; j++) {
					
					int buffRow = row + polymino[i][0][j];
					int buffCol = col + polymino[i][1][j];

					if (checkRange(buffRow, buffCol))
						buff += paper[buffRow][buffCol];
					else
						isPassed = false;
				}

				if (isPassed) {
					if (max < buff)
						max = buff;
				}

			}
		}
	}

	cout << max;

	return 0;

}