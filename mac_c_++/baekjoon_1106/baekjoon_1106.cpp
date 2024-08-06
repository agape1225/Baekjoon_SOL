#include <iostream>
#include <algorithm>

using namespace std;


int cost[21], customer[21];
int cache[100001] = {0};

int max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	int C, N;
	
	cin >> C >> N;

	for (int i = 1; i <= N; i++)
		cin >> cost[i] >> customer[i];

	// dp 배열 구하기
	for (int i = 1; i <= N; i++){
		for (int j = cost[i]; j <= 100000; j++){
			cache[j] = max(cache[j], cache[j - cost[i]] + customer[i]);
		}
			
	}
		

	// 출력
	for (int i = 1; i <= 100000; i++)
		if (cache[i] >= C) {
			cout << i;
			break;
		}
        
	return 0;
}