#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> stuff;
int cache[101][100001] = { 0 };


int main(void) {

	int N, K;
	int W, V;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> W >> V;
		stuff.push_back(make_pair(W, V));
	}

	for(int i = 1; i <= N; i++){
		W = stuff[i - 1].first;
		V = stuff[i - 1].second;
		for(int j = V; j < K; j++){
			if(j % V == 0){
				cache[i][j] = max()
			}
		}
	}
	
	cout << cache[N][K];


	return 0;
}