#include <stdio.h>

int main(void) {
	int buger[3];
	int drink[2];

	for (int i = 0; i < 3; i++) 
		scanf("%d", &buger[i]);
	for (int i = 0; i < 2; i++)
		scanf("%d", &drink[i]);

	int bugerMin = buger[0];
	int drinkMin = drink[0] > drink[1] ? drink[1] : drink[0];

	for (int i = 0; i < 3; i++) {
		if (bugerMin > buger[i])
			bugerMin = buger[i];
	}

	int result = bugerMin + drinkMin - 50;

	printf("%d", result);

}