#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define  SIZE 1000000

int main(void) {
	char input[SIZE];
	int count[26] = { 0 };
	int state = 1;
	
	scanf("%s", input);

	for (int i = 0; input[i]; i++) {
		if(islower(input[i]))
			input[i] = toupper(input[i]);
	}
	
	for (int i = 0; input[i]; i++)
		count[input[i] - 'A']++;

	char ans = 'A' + 0;
	int max = count[0];

	for (int i = 1; i < 26; i++) {
		if (max < count[i]){
			max = count[i];
			ans = 'A' + i;
			state = 1;
		}
		else if (max == count[i] && max) {
			state = 0;
		}
	}
	if (state)
		printf("%c", ans);
	else
		printf("?");
}