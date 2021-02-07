#include <stdio.h>
//#include <math.h>

int main(void) {
	while (1) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		
		if (x + y + z == 0)
			return 0;

		if (x > y) {
			if (x > z) {
				int buff = x;
				x = z;
				z = buff;
			}
		}
		else {
			if (y > z) {
				int buff = y;
				y = z;
				z = buff;
			}
		}

		if ((x * x) + (y * y) == (z * z)) {
			printf("right");
		}
		else
			printf("wrong");
		printf("\n");
	}
}