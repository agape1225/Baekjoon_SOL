#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define SIZE 25

using namespace std;

typedef struct point {
	int x;
	int y;
} point;

bool checkRange(int num) {
	if (0 <= num && num < 25)
		return true;
	else
		return false;
}

int getCount( int arr[SIZE][SIZE], int size, int locationX, int locationY) {
	
	queue<point> q;
	point buff;
	int count = 0;
	arr[locationX][locationY] = 0;
	buff.x = locationX;
	buff.y = locationY;

	q.push(buff);
	count++;

	while (!q.empty()) {
		point tmp = q.front();
		q.pop();

		//cout << tmp.x << ", " << tmp.y << endl;
		

		if (checkRange(tmp.x - 1) && arr[tmp.x - 1][tmp.y] == 1) {
			arr[tmp.x - 1][tmp.y] = 0;
			point plate;
			plate.x = tmp.x - 1;
			plate.y = tmp.y;
			q.push(plate);
			count++;
		}

		if (checkRange(tmp.x + 1) && arr[tmp.x + 1][tmp.y] == 1) {
			arr[tmp.x + 1][tmp.y] = 0;
			point plate;
			plate.x = tmp.x + 1;
			plate.y = tmp.y;
			q.push(plate);
			count++;
		}

		if (checkRange(tmp.y - 1) && arr[tmp.x][tmp.y - 1] == 1) {
			arr[tmp.x][tmp.y - 1] = 0;
			point plate;
			plate.x = tmp.x;
			plate.y = tmp.y - 1;
			q.push(plate);
			count++;
		}

		if (checkRange(tmp.y + 1) && arr[tmp.x][tmp.y + 1] == 1) {
			arr[tmp.x][tmp.y + 1] = 0;
			point plate;
			plate.x = tmp.x;
			plate.y = tmp.y + 1;
			q.push(plate);
			count++;
		}

	}

	//cout << endl << endl;

	return count;

}



int main(void) {

	int arr[SIZE][SIZE];
	int size;
	vector<int> ans;

	cin >> size;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			char buff;
			cin >> buff;
			arr[i][j] = buff - '0';
		}
	}

	/*for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}*/

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[i][j] == 1) {
				int buff = getCount(arr, size, i, j);
				ans.push_back(buff);
			}
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << endl;

	for (int i = 0; i < ans.size(); i++) {
		
		cout << ans[i] << endl;

	}

	return 0;


}