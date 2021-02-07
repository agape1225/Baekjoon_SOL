#include <stdio.h>
#include <math.h>


int main(void) {
	double r;
	scanf("%lf", &r);
	const double pi = acos(-1.0);
	printf("%.6lf\n%.6lf", r * r * pi, r * r * 2);
	return 0;
}