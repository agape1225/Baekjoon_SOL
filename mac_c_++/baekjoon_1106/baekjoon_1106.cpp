#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100*1000

int cost[21], customer[21];
int dp[MAX + 1];

int max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	int c, n;
	
    	// 입력
	scanf("%d%d", &c, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &cost[i], &customer[i]);

	// dp 배열 구하기
	for (int i = 1; i <= n; i++)
		for (int j = cost[i]; j <= MAX; j++)
			dp[j] = max(dp[j], dp[j - cost[i]] + customer[i]);

	// 출력
	for (int i = 1; i <= MAX; i++)
		if (dp[i] >= c) {
			printf("%d", i);
			break;
		}
        
	return 0;
}