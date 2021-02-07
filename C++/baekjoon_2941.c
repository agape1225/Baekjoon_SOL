#include <stdio.h>
#define SIZE 100

int main(void) {
	char input[SIZE];
	int count = 0;

	scanf("%s", input);

	for (int i = 0; input[i]; i++) {
		count++;
		if (i > 0) {
			
			if ((input[i - 1] == 'c' || input[i - 1] == 's' || input[i - 1] == 'z') && input[i] == '=') {
				if (i > 1 && input[i - 2] == 'd' && input[i - 1] == 'z')
					count = count - 2;
				else
					count--;
			}
			else if ((input[i - 1] == 'c' || input[i - 1] == 'd') && input[i] == '-') 
				count--;
			else if ((input[i - 1] == 'l' || input[i - 1] == 'n') && input[i] == 'j') 
				count--;
		}
	}
	printf("%d", count);
	
	return 0;
}