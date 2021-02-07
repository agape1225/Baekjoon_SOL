#include <stdio.h>
#define SIZE 3

int main(void) {
	char num1[SIZE+1];
	char num2[SIZE+1];

	int num_int1 = 0;
	int num_int2 = 0;

	scanf("%s %s", num1, num2);

	for (int i = 1, j  = 0; num1[j] && num2[j]; i = i * 10, j++) {
		num_int1 = num_int1 + ((num1[j] - '0') * i);
		num_int2 = num_int2 + ((num2[j] - '0') * i);
	}

	int ans = num_int1 > num_int2 ? num_int1 : num_int2;
	
	printf("%d", ans);
	
	return 0;
}