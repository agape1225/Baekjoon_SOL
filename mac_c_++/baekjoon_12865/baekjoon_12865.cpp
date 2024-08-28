#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
	int W[105];
	int V[105];
	int cache[105][100001];

int main(void){
	
	cin >> N >> K;

	for(int i = 0; i < N; i++){
		cin >> W[i] >> V[i];
	}

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= K; j++){
			if(j - W[i - 1] >= 0){
				cache[i][j] = max(cache[i - 1][j], cache[i - 1][j - W[i - 1]] + V[i - 1]);
			}else{
				cache[i][j] = cache[i - 1][j];
			}
		}
	}

	cout << cache[N][K];

	return 0;

}