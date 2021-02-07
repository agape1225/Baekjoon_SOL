#include <iostream>
#include <cmath>

using namespace std;

typedef struct Point {
	int x;
	int y;
	int r;
} point;

int main(void) {

	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {

		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		point p1, p2;

		if (r1 >= r2) {
			p1.x = x1;
			p1.y = y1;
			p1.r = r1;

			p2.x = x2;
			p2.y = y2;
			p2.r = r2;

		}
		else {
			p1.x = x2;
			p1.y = y2;
			p1.r = r2;

			p2.x = x1;
			p2.y = y1;
			p2.r = r1;
		}

		double distance = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
		if (distance > p1.r) {

			if (distance < p1.r + p2.r)
				cout << 2;
			else if (distance == p1.r + p2.r)
				cout << 1;
			else
				cout << 0;

		}
		else if (distance == p1.r) {
			cout << 2;
		}
		else {

			if (distance == 0 && p1.r == p2.r)
				cout << -1;
			else {
				if (p2.r * 2 == p1.r)
					cout << 1;
				else {
					if (distance + p2.r < p1.r)
						cout << 0;
					else if (distance + p2.r == p1.r)
						cout << 1;
					else
						cout << 2;
				}
			}

		}
		cout << endl;

	}

	return 0;
}