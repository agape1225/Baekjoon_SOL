#include <stdio.h>
#define SIZE 80

int main(void) {
	int input;
	scanf("%d", &input);
	
	for (int i = 0; i < input; i++) {
		char msg[SIZE];
		int score = 0;
		int contin = 0;
		scanf("%s", msg);
		for (int i = 0; msg[i]; i++) {
			if (msg[i] == 'O') {
				contin++;
				score = score + contin;
			}
			else
				contin = 0;
		}
		printf("%d\n", score);
	}
	return 0;
}