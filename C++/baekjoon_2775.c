#include <stdio.h>
#define SIZE 15

int main(void) {
	int caseTime;
	scanf("%d",&caseTime);
	

	int apart[SIZE][SIZE] = { 0 };
	int layer = 0;
	int roomNum = 1;

	for (int i = roomNum; i < SIZE; i++)
		apart[0][i] = i;
	
	for (int i = 1; i < SIZE; i++) {
		for (int j = roomNum; j < SIZE; j++) {
			for (int k = roomNum; k <= j; k++)
				apart[i][j] += apart[i - 1][k];

		}
	}

	/*for (int i = layer; i < SIZE; i++) {
		for (int j = roomNum; j < SIZE; j++)
			printf("%10d",apart[i][j]);
		printf("\n");
	}*/
	
	for (int i = 0; i < caseTime; i++) {
		int x; // layer
		int n; // room number
		int ans = 0;
		scanf("%d", &x);
		scanf("%d", &n);
		printf("%d\n", apart[x][n]);
	}
	
	return 0;
}